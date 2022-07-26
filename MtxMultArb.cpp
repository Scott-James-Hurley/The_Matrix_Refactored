#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <Eigen/Dense>
#include <Math/SMatrix.h>

#include "/acts/Core/include/Acts/Definitions/Algebra.hpp"
#include "/acts/Core/include/Acts/Definitions/Common.hpp"
#include "/acts/Core/include/Acts/Utilities/BinningType.hpp"

#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

template<size_t M1Rows, size_t M1ColumnsM2Rows, size_t M2Columns>
ROOT::Math::SMatrix<double, M1Rows, M2Columns> sMatMult(const ROOT::Math::SMatrix<double, M1Rows, M1ColumnsM2Rows> &sm1, const ROOT::Math::SMatrix<double, M1ColumnsM2Rows, M2Columns> &sm2)
{
  return ROOT::Math::operator*(sm1, sm2);
}

template<size_t M1Rows, size_t M1ColumnsM2Rows, size_t M2Columns>
ROOT::Math::SMatrix<double, M1Rows, M2Columns> sMatMultSym(const ROOT::Math::SMatrix<double, M1Rows, M1ColumnsM2Rows> &sm1, const ROOT::Math::SMatrix<double, M1ColumnsM2Rows, M1ColumnsM2Rows, ROOT::Math::MatRepSym<double, M1ColumnsM2Rows>> &sm2)
{
  return ROOT::Math::operator*(sm1, sm2);
}

template<size_t M1Rows, size_t M1ColumnsM2Rows, size_t M2Columns>
ROOT::Math::SMatrix<double, M1Rows, M2Columns> sMatMultConv(const Eigen::Matrix<double, M1Rows, M1ColumnsM2Rows> &m1, const Eigen::Matrix<double, M1ColumnsM2Rows, M2Columns> &m2)
{
  return ROOT::Math::operator*(ROOT::Math::Transpose(ROOT::Math::SMatrix<double, M1Rows, M1ColumnsM2Rows>(m1.data(), m1.data() + m1.size())), ROOT::Math::Transpose(ROOT::Math::SMatrix<double, M1ColumnsM2Rows, M2Columns>(m2.data(), m2.data() + m2.size())));
}

template<size_t M1Rows, size_t M1ColumnsM2Rows, size_t M2Columns>
ROOT::Math::SMatrix<double, M1Rows, M2Columns> sMatMultConvEigen(const Eigen::Matrix<double, M1Rows, M1ColumnsM2Rows> &m1, const Eigen::Matrix<double, M1ColumnsM2Rows, M2Columns> &m2)
{
  const Eigen::Matrix<double, M1ColumnsM2Rows, M1Rows> m1T = m1.transpose();
  const Eigen::Matrix<double, M2Columns, M1ColumnsM2Rows> m2T = m2.transpose();

  return ROOT::Math::operator*(ROOT::Math::SMatrix<double, M1ColumnsM2Rows, M1Rows>(m1T.data(), m1T.data() + m1T.size()), ROOT::Math::SMatrix<double, M2Columns, M1ColumnsM2Rows>(m2T.data(), m2T.data() + m2T.size()));
}

template<size_t M1Rows, size_t M1ColumnsM2Rows, size_t M2Columns>
Eigen::Matrix<double, M1Rows, M2Columns> eigenMult(const Eigen::Matrix<double, M1Rows, M1ColumnsM2Rows> &m1, const Eigen::Matrix<double, M1ColumnsM2Rows, M2Columns> &m2)
{
  return m1 * m2;
}

template<size_t M1Rows, size_t M1ColumnsM2Rows, size_t M2Columns>
Eigen::Matrix<double, M1Rows, M2Columns> eigenMultSym(const Eigen::Matrix<double, M1Rows, M1ColumnsM2Rows> &m1, const Eigen::TriangularView<Eigen::Matrix<double, M1ColumnsM2Rows, M1ColumnsM2Rows>, 1U> &m2)
{
  return m1 * m2;
}

template <typename A, typename B>
Acts::ActsMatrix<A::RowsAtCompileTime, B::ColsAtCompileTime> blockedMult(const A& a, const B& b) {
  constexpr int M = A::RowsAtCompileTime;
  constexpr int N = A::ColsAtCompileTime;
  constexpr int P = B::ColsAtCompileTime;

  static_assert(N == B::RowsAtCompileTime);

  if constexpr (M <= 4 && N <= 4 && P <= 4) {
    return a * b;
  } else {
    constexpr int M1 = M / 2;
    constexpr int M2 = (M + 1) / 2;
    constexpr int N1 = N / 2;
    constexpr int N2 = (N + 1) / 2;
    constexpr int P1 = P / 2;
    constexpr int P2 = (P + 1) / 2;

    Acts::ActsMatrix<M, P> r;

    r.template topLeftCorner<M1, P1>().noalias() =
        a.template topLeftCorner<M1, N1>() *
            b.template topLeftCorner<N1, P1>() +
        a.template topRightCorner<M1, N2>() *
            b.template bottomLeftCorner<N2, P1>();

    r.template topRightCorner<M1, P2>().noalias() =
        a.template topLeftCorner<M1, N1>() *
            b.template topRightCorner<N1, P2>() +
        a.template topRightCorner<M1, N2>() *
            b.template bottomRightCorner<N2, P2>();

    r.template bottomLeftCorner<M2, P1>().noalias() =
        a.template bottomLeftCorner<M2, N1>() *
            b.template topLeftCorner<N1, P1>() +
        a.template bottomRightCorner<M2, N2>() *
            b.template bottomLeftCorner<N2, P1>();

    r.template bottomRightCorner<M2, P2>().noalias() =
        a.template bottomLeftCorner<M2, N1>() *
            b.template topRightCorner<N1, P2>() +
        a.template bottomRightCorner<M2, N2>() *
            b.template bottomRightCorner<N2, P2>();

    return r;
  }
}

int main()
{
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  srand(time(0));

  const int ITERATIONS = 10000000;
  const size_t m1Rows = 15;
  const size_t m1ColumnsM2Rows = 15;
  const size_t m2Columns = 15;
  const int triangleNumber = m1ColumnsM2Rows * (m2Columns + 1) / 2;
  double total = 0;

  Eigen::Matrix<double, m1Rows, m1ColumnsM2Rows> m1 = Eigen::Matrix<double, m1Rows, m1ColumnsM2Rows>::Random(m1Rows, m1ColumnsM2Rows);
  Eigen::Matrix<double, m1ColumnsM2Rows, m2Columns> m2 = Eigen::Matrix<double, m1ColumnsM2Rows, m2Columns>::Random(m1ColumnsM2Rows, m2Columns);
  Eigen::TriangularView<Eigen::Matrix<double, m1ColumnsM2Rows, m2Columns>, 1U> m2T = m2.triangularView<Eigen::Lower>();

  std::vector<double> v(triangleNumber);

  for (int i = 0; i < triangleNumber; i++) {
    v[i] = double(rand());
  }

  ROOT::Math::SMatrix<double, m1Rows, m1ColumnsM2Rows> sm1 = ROOT::Math::Transpose(ROOT::Math::SMatrix<double, m1Rows, m1ColumnsM2Rows>(m1.data(), m1.data() + m1.size()));
  ROOT::Math::SMatrix<double, m1ColumnsM2Rows, m2Columns> sm2 = ROOT::Math::Transpose(ROOT::Math::SMatrix<double, m1ColumnsM2Rows, m2Columns>(m2.data(), m2.data() + m2.size()));
  ROOT::Math::SMatrix<double, m1ColumnsM2Rows, m1ColumnsM2Rows, ROOT::Math::MatRepSym<double, m1ColumnsM2Rows>> sm2S(v.begin(), v.end());

  int randXcoord = rand() % m1Rows;
  int randYcoord = rand() % m1ColumnsM2Rows;
  int randXTotalcoord = rand() % m1Rows;
  int randYTotalcoord = rand() % m2Columns;

  auto eigenT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += eigenMult<m1Rows, m1ColumnsM2Rows, m2Columns>(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto eigenT2 = high_resolution_clock::now();
  duration<double, std::milli> eigenTime = eigenT2 - eigenT1;
  std::cout << "eigenMult: " << eigenTime.count() << "ms\n\n";

  auto smatrixT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(randXcoord, randYcoord) = (double)rand();
    total += sMatMult<m1Rows, m1ColumnsM2Rows, m2Columns>(sm1, sm2)(randXTotalcoord, randYTotalcoord);
  }

  auto smatrixT2 = high_resolution_clock::now();
  duration<double, std::milli> smatrixTime = smatrixT2 - smatrixT1;
  std::cout << "smatrixMult: " << smatrixTime.count() << "ms\n\n";

  auto smatrixConvT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += sMatMultConv<m1Rows, m1ColumnsM2Rows, m2Columns>(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto smatrixConvT2 = high_resolution_clock::now();
  duration<double, std::milli> smatrixConvTime = smatrixConvT2 - smatrixConvT1;
  std::cout << "smatrixMultEigenConv: " << smatrixConvTime.count() << "ms\n\n";

  auto smatrixConvET1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += sMatMultConvEigen<m1Rows, m1ColumnsM2Rows, m2Columns>(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto smatrixConvET2 = high_resolution_clock::now();
  duration<double, std::milli> smatrixConvETime = smatrixConvET2 - smatrixConvET1;
  std::cout << "sMatMultConvEigen: " << smatrixConvETime.count() << "ms\n\n";

  if(m1ColumnsM2Rows == m2Columns) {
    auto eigenSymT1 = high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; i++)
    {
      m1(randXcoord, randYcoord) = (double)rand();
      total += eigenMultSym<m1Rows, m1ColumnsM2Rows, m2Columns>(m1, m2T)(randXTotalcoord, randYTotalcoord);
    }

    auto eigenSymT2 = high_resolution_clock::now();
    duration<double, std::milli> eigenSymTime = eigenSymT2 - eigenSymT1;
    std::cout << "eigenMultSym: " << eigenSymTime.count() << "ms\n\n";

    auto smatrixSymT1 = high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; i++)
    {
      sm1(randXcoord, randYcoord) = (double)rand();
      total += sMatMultSym<m1Rows, m1ColumnsM2Rows, m2Columns>(sm1, sm2S)(randXTotalcoord, randYTotalcoord);
    }

    auto smatrixSymT2 = high_resolution_clock::now();
    duration<double, std::milli> smatrixSymTime = smatrixSymT2 - smatrixSymT1;
    std::cout << "smatrixMultSym: " << smatrixSymTime.count() << "ms\n\n";

    auto actsMatrixT1 = high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; i++)
    {
      m1(randXcoord, randYcoord) = (double)rand();
      total += blockedMult<Eigen::Matrix<double, m1Rows, m1ColumnsM2Rows>, Eigen::Matrix<double, m1ColumnsM2Rows, m2Columns>>(m1, m2)(randXTotalcoord, randYTotalcoord);
    }

    auto actsMatrixT2 = high_resolution_clock::now();
    duration<double, std::milli> actsMatrixTime = actsMatrixT2 - actsMatrixT1;
    std::cout << "blockedMult: " << actsMatrixTime.count() << "ms\n\n";
  }

  std::cout << total << "\n\n";

  return 0;
}
