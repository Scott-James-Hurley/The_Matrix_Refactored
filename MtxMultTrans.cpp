#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Eigen/Dense"
#include "/usr/local/include/Math/SMatrix.h"

ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> rootMatMult(const ROOT::Math::SMatrix<double, 6, 6> &m2, const ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> &m1)
{
  return ROOT::Math::Similarity(m2, m1);
}

Eigen::Matrix<double, 6, 6> matrixMultFastLoop(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result;
  int ResultPtrIndex = 0;

  const double *m1Ptr = m1.data();
  const double *m3Ptr = m3.data();
  double *resultPtr = result.data();

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      *(resultPtr + ResultPtrIndex) = *(m1Ptr + rowIndex) * *(m3Ptr + columnIndex) + *(m1Ptr + rowIndex + 6) * *(m3Ptr + columnIndex + 6) + *(m1Ptr + rowIndex + 12) * *(m3Ptr + columnIndex + 12) + *(m1Ptr + rowIndex + 18) * *(m3Ptr + columnIndex + 18) + *(m1Ptr + rowIndex + 24) * *(m3Ptr + columnIndex + 24) + *(m1Ptr + rowIndex + 30) * *(m3Ptr + columnIndex + 30);

      ResultPtrIndex++;
    }
  }

  return result;
}

Eigen::Matrix<double, 6, 6> matrixMultFastLoopTheTriple(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result = Eigen::Matrix<double, 6, 6>::Zero(6, 6);
  int ResultPtrIndex = 0;

  const double *m1Ptr = m1.data();
  const double *m3Ptr = m3.data();
  double *resultPtr = result.data();

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      for (int offset = 0; offset < 31; offset = offset + 6)
      {
        *(resultPtr + ResultPtrIndex) += *(m1Ptr + rowIndex + offset) * *(m3Ptr + columnIndex + offset);
      }

      ResultPtrIndex++;
    }
  }

  return result;
}

Eigen::Matrix<double, 6, 6> matrixMultFastLoopTripleRef(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result = Eigen::Matrix<double, 6, 6>::Zero(6, 6);
  int ResultDataIndex = 0;

  const double *m1Data = m1.data();
  const double *m3Data = m3.data();
  double *resultData = result.data();

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      for (int offset = 0; offset < 31; offset = offset + 6)
      {
        resultData[ResultDataIndex] += m1Data[rowIndex + offset] * m3Data[columnIndex + offset];
      }

      ResultDataIndex++;
    }
  }

  return result;
}

Eigen::Matrix<double, 6, 6> matrixMultFastLoopRef(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result;
  int ResultDataIndex = 0;

  const double *m1Data = m1.data();
  const double *m3Data = m3.data();
  double *resultData = result.data();

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      resultData[ResultDataIndex] = m1Data[rowIndex] * m3Data[columnIndex] + m1Data[rowIndex + 6] * m3Data[columnIndex + 6] + m1Data[rowIndex + 12] * m3Data[columnIndex + 12] + m1Data[rowIndex + 18] * m3Data[columnIndex + 18] + m1Data[rowIndex + 24] * m3Data[columnIndex + 24] + m1Data[rowIndex + 30] * m3Data[columnIndex + 30];
      ResultDataIndex++;
    }
  }

  return result;
}

Eigen::Matrix<double, 6, 6> matrixMultFastLoopAccess(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result;

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      result(columnIndex, rowIndex) = m1(rowIndex, 0) * m3(columnIndex, 0) + m1(rowIndex, 1) * m3(columnIndex, 1) + m1(rowIndex, 2) * m3(columnIndex, 2) + m1(rowIndex, 3) * m3(columnIndex, 3) + m1(rowIndex, 4) * m3(columnIndex, 4) + m1(rowIndex, 5) * m3(columnIndex, 5);
    }
  }

  return result;
}

Eigen::Matrix<double, 6, 6> matrixMultOld(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  return m1 * m2 * m1.transpose();
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

  double a[36];
  std::vector<double> v(21);

   for (int i = 0; i < 36; ++i)
    a[i] = double(rand());

  for (int i = 0; i < 21; ++i)
    v[i] = double(rand());

  ROOT::Math::SMatrix<double, 6> sm1(a, 36);
  ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> sm2(v.begin(), v.end());

  auto sampleT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += m1(0, 0);
  }

  auto sampleT2 = high_resolution_clock::now();
  duration<double, std::milli> sampleTime = sampleT2 - sampleT1;

  auto loopT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoop(m1, m2)(0, 0);
  }

  auto loopT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTime = loopT2 - loopT1;
  std::cout << "Loop: " << loopTime.count() - sampleTime.count() << "ms\n\n";

  auto loopTheTripleT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoopTheTriple(m1, m2)(0, 0);
  }

  auto loopTheTripleT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTheTripleTime = loopTheTripleT2 - loopTheTripleT1;
  std::cout << "Triple: " << loopTheTripleTime.count() - sampleTime.count() << "ms\n\n";

  auto loopAccessT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoopAccess(m1, m2)(0, 0);
  }

  auto loopAccessT2 = high_resolution_clock::now();
  duration<double, std::milli> loopAccessTime = loopAccessT2 - loopAccessT1;
  std::cout << "Access: " << loopAccessTime.count() - sampleTime.count() << "ms\n\n";

  auto loopRefT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoopRef(m1, m2)(0, 0);
  }

  auto loopRefT2 = high_resolution_clock::now();
  duration<double, std::milli> loopRefTime = loopRefT2 - loopRefT1;
  std::cout << "Ref: " << loopRefTime.count() - sampleTime.count() << "ms\n\n";

  auto loopTripleRefT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoopTripleRef(m1, m2)(0, 0);
  }

  auto loopTripleRefT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTripleRefTime = loopTripleRefT2 - loopTripleRefT1;
  std::cout << "TripleRef: " << loopTripleRefTime.count() - sampleTime.count() << "ms\n\n";

  auto rootT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(0, 0) = (double)rand();
    total += rootMatMult(sm1, sm2)(0, 0);
  }

  auto rootT2 = high_resolution_clock::now();
  duration<double, std::milli> rootTime = rootT2 - rootT1;
  std::cout << "ROOT: " << rootTime.count() - sampleTime.count() << "ms\n\n";

  auto oldT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultOld(m1, m2)(0, 0);
  }

  auto oldT2 = high_resolution_clock::now();
  duration<double, std::milli> oldTime = oldT2 - oldT1;
  std::cout << "Old: " << oldTime.count() - sampleTime.count() << "ms\n\n";

  return 0;
}
