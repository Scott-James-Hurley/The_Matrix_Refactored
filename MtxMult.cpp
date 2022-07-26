#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <Eigen/Dense>
#include <Math/SMatrix.h>

//Time taken: 215.794ms
ROOT::Math::SMatrix<double, 6, 6> sMatMult(const ROOT::Math::SMatrix<double, 6, 6> &sm1, const ROOT::Math::SMatrix<double, 6, 6> &sm2)
{
  return ROOT::Math::operator*(sm1, sm2);
}

//Time taken: 176.606ms
ROOT::Math::SMatrix<double, 6, 6> sMatMultSym(const ROOT::Math::SMatrix<double, 6, 6> &sm1, const ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> &sm2)
{
  return ROOT::Math::operator*(sm1, sm2);
}

//Time taken: 577.497ms
ROOT::Math::SMatrix<double, 6, 6> sMatMultConv(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  return ROOT::Math::operator*(ROOT::Math::Transpose(ROOT::Math::SMatrix<double, 6>(m1.data(), m1.data() + m1.size())), ROOT::Math::Transpose(ROOT::Math::SMatrix<double, 6>(m2.data(), m2.data() + m2.size())));
}

//Time taken: 462.525ms
ROOT::Math::SMatrix<double, 6, 6> sMatMultConvEigen(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m1T = m1.transpose();
  const Eigen::Matrix<double, 6, 6> m2T = m2.transpose();

  return ROOT::Math::operator*(ROOT::Math::SMatrix<double, 6>(m1.data(), m1.data() + m1.size()), ROOT::Math::SMatrix<double, 6>(m2.data(), m2.data() + m2.size()));
}

//Time taken: 138.986ms
Eigen::Matrix<double, 6, 6> eigenMult(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  return m1 * m2;
}

//Time taken: 2045.05ms
Eigen::Matrix<double, 6, 6> eigenMultSym(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::TriangularView<Eigen::Matrix<double, 6, 6>, 1U> &m2)
{
  return m1 * m2;
}

//Time taken: 1244.88ms
Eigen::Matrix<double, 6, 6> eigenMultSymSa(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::SelfAdjointView<Eigen::Matrix<double, 6, 6>, 2U> &m2)
{
  return m1* m2;
}

int main()
{
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  srand(time(0));

  const int ITERATIONS = 10000000;
  double total = 0;

  Eigen::Matrix<double, 6, 6> m1 = Eigen::Matrix<double, 6, 6>::Random(6, 6);
  Eigen::Matrix<double, 6, 6> m2 = Eigen::Matrix<double, 6, 6>::Random(6, 6);
  Eigen::TriangularView<Eigen::Matrix<double, 6, 6>, 1U> m2T = m2.triangularView<Eigen::Lower>();
  Eigen::SelfAdjointView<Eigen::Matrix<double, 6, 6>, 2U> m2SA = m2.selfadjointView<Eigen::Upper>();

  double a[36];
  double b[36];
  std::vector<double> v(21);

  for (int i = 0; i < 36; ++i)
    a[i] = double(rand());

  for (int i = 0; i < 36; ++i)
    b[i] = double(rand());

  for (int i = 0; i < 21; ++i)
    v[i] = double(rand());

  ROOT::Math::SMatrix<double, 6> sm1(a,36);
  ROOT::Math::SMatrix<double, 6> sm2(b,36);
  ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> sm2S(v.begin(), v.end());

  int randXcoord = rand() % 6;
  int randYcoord = rand() % 6;
  int randXTotalcoord = rand() % 6;
  int randYTotalcoord = rand() % 6;

  auto sampleT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += m1(randXTotalcoord, randYTotalcoord);
  }

  auto sampleT2 = high_resolution_clock::now();
  duration<double, std::milli> sampleTime = sampleT2 - sampleT1;
  
  auto smatrixSampleT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(randXcoord, randYcoord) = (double)rand();
    total += sm1(randXTotalcoord, randYTotalcoord);
  }

  auto smatrixSampleT2 = high_resolution_clock::now();
  duration<double, std::milli> smatrixSampleTime = smatrixSampleT2 - smatrixSampleT1;

  auto eigenT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += eigenMult(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto eigenT2 = high_resolution_clock::now();
  duration<double, std::milli> eigenTime = eigenT2 - eigenT1;
  std::cout << "eigenMult: " << eigenTime.count() - sampleTime.count() << "ms\n\n";

  auto eigenSymSaT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += eigenMultSymSa(m1, m2SA)(randXTotalcoord, randYTotalcoord);
  }

  auto eigenSymSaT2 = high_resolution_clock::now();
  duration<double, std::milli> eigenSymSaTime = eigenSymSaT2 - eigenSymSaT1;
  std::cout << "eigenMultSymSa: " << eigenSymSaTime.count() - sampleTime.count() << "ms\n\n";

  auto eigenSymT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += eigenMultSym(m1, m2T)(randXTotalcoord, randYTotalcoord);
  }

  auto eigenSymT2 = high_resolution_clock::now();
  duration<double, std::milli> eigenSymTime = eigenSymT2 - eigenSymT1;
  std::cout << "eigenMultSym: " << eigenSymTime.count() - sampleTime.count() << "ms\n\n";


  auto smatrixT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(randXcoord, randYcoord) = (double)rand();
    total += sMatMult(sm1, sm2)(randXTotalcoord, randYTotalcoord);
  }

  auto smatrixT2 = high_resolution_clock::now();
  duration<double, std::milli> smatrixTime = smatrixT2 - smatrixT1;
  std::cout << "smatrixMult: " << smatrixTime.count() - smatrixSampleTime.count() << "ms\n\n";

  auto smatrixSymT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(randXcoord, randYcoord) = (double)rand();
    total += sMatMultSym(sm1, sm2S)(randXTotalcoord, randYTotalcoord);
  }

  auto smatrixSymT2 = high_resolution_clock::now();
  duration<double, std::milli> smatrixSymTime = smatrixSymT2 - smatrixSymT1;
  std::cout << "smatrixMultSym: " << smatrixSymTime.count() - smatrixSampleTime.count() << "ms\n\n";
  
  auto smatrixConvT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(randXcoord, randYcoord) = (double)rand();
    total += sMatMultConv(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto smatrixConvT2 = high_resolution_clock::now();
  duration<double, std::milli> smatrixConvTime = smatrixConvT2 - smatrixConvT1;
  std::cout << "smatrixMultEigenConv: " << smatrixConvTime.count() - sampleTime.count() << "ms\n\n";

  auto smatrixConvET1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(randXcoord, randYcoord) = (double)rand();
    total += sMatMultConvEigen(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto smatrixConvET2 = high_resolution_clock::now();
  duration<double, std::milli> smatrixConvETime = smatrixConvET2 - smatrixConvET1;
  std::cout << "sMatMultConvEigen: " << smatrixConvETime.count() - sampleTime.count() << "ms\n\n";

  std::cout << total;

  return 0;
}
