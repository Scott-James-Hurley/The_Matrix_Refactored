#include <iostream>
#include <chrono>
#include <thread>
#include "Eigen/Dense"

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

  const int ITERATIONS = 10000000;

  Eigen::Matrix<double, 6, 6> m1 = Eigen::Matrix<double, 6, 6>::Random(6, 6);
  Eigen::Matrix<double, 6, 6> m2 = Eigen::Matrix<double, 6, 6>::Random(6, 6);

  auto t1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    matrixMultFastLoop(m1, m2);
  }

  auto t2 = high_resolution_clock::now();

  duration<double, std::milli> ms_double1 = t2 - t1;

  std::cout << "Loop:";
  std::cout << ms_double1.count() << "ms\n\n";

  auto t5 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    matrixMultFastLoopTheTriple(m1, m2);
  }

  auto t6 = high_resolution_clock::now();

  duration<double, std::milli> ms_double3 = t6 - t5;
  std::cout << "Triple:";
  std::cout << ms_double3.count() << "ms\n\n";

  auto t7 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    matrixMultFastLoopAccess(m1, m2);
  }

  auto t8 = high_resolution_clock::now();

  duration<double, std::milli> ms_double4 = t8 - t7;
  std::cout << "Access:";
  std::cout << ms_double4.count() << "ms\n\n";

  auto t9 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    matrixMultFastLoopRef(m1, m2);
  }

  auto t10 = high_resolution_clock::now();

  duration<double, std::milli> ms_double5 = t10 - t9;
  std::cout << "Ref:";
  std::cout << ms_double5.count() << "ms\n\n";

  auto t11 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    matrixMultFastLoopTripleRef(m1, m2);
  }

  auto t12 = high_resolution_clock::now();

  duration<double, std::milli> ms_double6 = t12 - t11;
  std::cout << "TripleRef:";
  std::cout << ms_double6.count() << "ms\n\n";

  auto t3 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    matrixMultOld(m1, m2);
  }

  auto t4 = high_resolution_clock::now();

  duration<double, std::milli> ms_double2 = t4 - t3;
  std::cout << "Old:";
  std::cout << ms_double2.count() << "ms\n\n";

  return 0;
}