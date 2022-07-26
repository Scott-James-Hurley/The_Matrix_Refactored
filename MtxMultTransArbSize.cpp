#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cblas.h>
#include <stdio.h>
#include <stdlib.h>
#include <Eigen/Dense>
#include <Math/SMatrix.h>

template<size_t M1Rows, size_t m1ColumnsM2RowsColumns>
ROOT::Math::SMatrix<double, M1Rows, M1Rows, ROOT::Math::MatRepSym<double, M1Rows>> sMatrixSimilarity(const ROOT::Math::SMatrix<double, M1Rows, m1ColumnsM2RowsColumns> &m1, const ROOT::Math::SMatrix<double, m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns, ROOT::Math::MatRepSym<double, m1ColumnsM2RowsColumns>> &m2)
{
  return ROOT::Math::Similarity(m1, m2);
}

template<size_t M1Rows, size_t m1ColumnsM2RowsColumns>
Eigen::Matrix<double, M1Rows, M1Rows> matrixMultFastLoopTheTriple(const Eigen::Matrix<double, M1Rows, m1ColumnsM2RowsColumns> &m1, const Eigen::Matrix<double, m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns> &m2)
{
  const Eigen::Matrix<double, M1Rows, m1ColumnsM2RowsColumns> m3 = m1 * m2;
  Eigen::Matrix<double, M1Rows, M1Rows> result = Eigen::Matrix<double, M1Rows, M1Rows>::Zero(M1Rows, M1Rows);
  int ResultPtrIndex = 0;

  const double *m1Ptr = m1.data();
  const double *m3Ptr = m3.data();
  double *resultPtr = result.data();

  for (int rowIndex = 0; rowIndex < M1Rows; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < M1Rows; columnIndex++)
    {
      for (int offset = 0; offset < m1ColumnsM2RowsColumns; offset++)
      {
        *(resultPtr + ResultPtrIndex) += *(m1Ptr + rowIndex + offset * M1Rows) * *(m3Ptr + offset * M1Rows + columnIndex);
      }

      ResultPtrIndex++;
    }
  }

  return result;
}

template<size_t M1Rows, size_t m1ColumnsM2RowsColumns>
Eigen::Matrix<double, M1Rows, M1Rows> matrixMultFastLoopTripleInit(const Eigen::Matrix<double, M1Rows, m1ColumnsM2RowsColumns> &m1, const Eigen::Matrix<double, m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns> &m2)
{
  const Eigen::Matrix<double, M1Rows, m1ColumnsM2RowsColumns> m3 = m1 * m2;
  Eigen::Matrix<double, M1Rows, M1Rows> result;
  int ResultPtrIndex = 0;

  const double *m1Ptr = m1.data();
  const double *m3Ptr = m3.data();
  double *resultPtr = result.data();

  for (int rowIndex = 0; rowIndex < M1Rows; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < M1Rows; columnIndex++)
    {
      *(resultPtr + ResultPtrIndex) = 0;

      for (int offset = 0; offset < m1ColumnsM2RowsColumns; offset++)
      {
        *(resultPtr + ResultPtrIndex) += *(m1Ptr + rowIndex + offset * M1Rows) * *(m3Ptr + offset * M1Rows + columnIndex);
      }

      ResultPtrIndex++;
    }
  }

  return result;
}

template<size_t M1Rows, size_t m1ColumnsM2RowsColumns>
Eigen::Matrix<double, M1Rows, M1Rows> matrixMultFastLoopTripleRef(const Eigen::Matrix<double, M1Rows, m1ColumnsM2RowsColumns> &m1, const Eigen::Matrix<double, m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns> &m2)
{
  const Eigen::Matrix<double, M1Rows, m1ColumnsM2RowsColumns> m3 = m1 * m2;
  Eigen::Matrix<double, M1Rows, M1Rows> result = Eigen::Matrix<double, M1Rows, M1Rows>::Zero(M1Rows, M1Rows);
  int ResultDataIndex = 0;

  const double *m1Data = m1.data();
  const double *m3Data = m3.data();
  double *resultData = result.data();

  for (int rowIndex = 0; rowIndex < M1Rows; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < M1Rows; columnIndex++)
    {
      for (int offset = 0; offset < m1ColumnsM2RowsColumns; offset++)
      {
        resultData[ResultDataIndex] += m1Data[rowIndex + offset * M1Rows] * m3Data[offset * M1Rows + columnIndex];
      }

      ResultDataIndex++;
    }
  }

  return result;
}

template<size_t M1Rows, size_t m1ColumnsM2RowsColumns>
Eigen::Matrix<double, M1Rows, M1Rows> matrixMultFastLoopTripleRefInit(const Eigen::Matrix<double, M1Rows, m1ColumnsM2RowsColumns> &m1, const Eigen::Matrix<double, m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns> &m2)
{
  const Eigen::Matrix<double, M1Rows, m1ColumnsM2RowsColumns> m3 = m1 * m2;
  Eigen::Matrix<double, M1Rows, M1Rows> result;
  int ResultDataIndex = 0;

  const double *m1Data = m1.data();
  const double *m3Data = m3.data();
  double *resultData = result.data();

  for (int rowIndex = 0; rowIndex < M1Rows; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < M1Rows; columnIndex++)
    {
      resultData[ResultDataIndex] = 0;

      for (int offset = 0; offset < m1ColumnsM2RowsColumns; offset++)
      {
        resultData[ResultDataIndex] += m1Data[rowIndex + offset * M1Rows] * m3Data[offset * M1Rows + columnIndex];
      }

      ResultDataIndex++;
    }
  }

  return result;
}

template<size_t M1Rows, size_t m1ColumnsM2RowsColumns>
Eigen::Matrix<double, M1Rows, M1Rows> matrixMultEigen(const Eigen::Matrix<double, M1Rows, m1ColumnsM2RowsColumns> &m1, const Eigen::Matrix<double, m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns> &m2)
{
  return m1 * m2 * m1.transpose();
}

int main()
{
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  const size_t m1Rows = 8;
  const size_t m1ColumnsM2RowsColumns = 8;

  srand(time(0));

  const int ITERATIONS = 10000000;
  double total = 0;

  Eigen::Matrix<double, m1Rows, m1ColumnsM2RowsColumns> m1 = Eigen::Matrix<double, m1Rows, m1ColumnsM2RowsColumns>::Random(m1Rows, m1ColumnsM2RowsColumns);
  Eigen::Matrix<double, m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns> m2 = Eigen::Matrix<double, m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns>::Random(m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns);

  double a[m1Rows * m1ColumnsM2RowsColumns];
  int triangleNumber = m1ColumnsM2RowsColumns * (m1ColumnsM2RowsColumns + 1) / 2;
  std::vector<double> v(triangleNumber);

  for (int i = 0; i < m1Rows * m1ColumnsM2RowsColumns; i++) {
    a[i] = double(rand());
  }

  for (int i = 0; i < triangleNumber; i++) {
    v[i] = double(rand());
  }

  ROOT::Math::SMatrix<double, m1Rows, m1ColumnsM2RowsColumns> sm1(a, m1Rows * m1ColumnsM2RowsColumns);
  ROOT::Math::SMatrix<double, m1ColumnsM2RowsColumns, m1ColumnsM2RowsColumns, ROOT::Math::MatRepSym<double, m1ColumnsM2RowsColumns>> sm2(v.begin(), v.end());

  int randXcoord = rand() % m1Rows;
  int randYcoord = rand() % m1ColumnsM2RowsColumns;
  int randXTotalcoord = rand() % m1Rows;
  int randYTotalcoord = rand() % m1Rows;

  auto loopTheTripleT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopTheTriple<m1Rows, m1ColumnsM2RowsColumns>(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto loopTheTripleT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTheTripleTime = loopTheTripleT2 - loopTheTripleT1;
  std::cout << "matrixMultFastLoopTheTriple: " << loopTheTripleTime.count() << "ms\n\n";

  auto loopTripleRefT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopTripleRef<m1Rows, m1ColumnsM2RowsColumns>(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto loopTripleRefT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTripleRefTime = loopTripleRefT2 - loopTripleRefT1;
  std::cout << "matrixMultFastLoopTripleRef: " << loopTripleRefTime.count() << "ms\n\n";

  auto loopTripleRefInitT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopTripleRefInit<m1Rows, m1ColumnsM2RowsColumns>(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto loopTripleRefInitT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTripleRefInitTime = loopTripleRefInitT2 - loopTripleRefInitT1;
  std::cout << "matrixMultFastLoopTripleRefInit: " << loopTripleRefInitTime.count() << "ms\n\n";

  auto rootT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(randXcoord, randYcoord) = (double)rand();
    total += sMatrixSimilarity<m1Rows, m1ColumnsM2RowsColumns>(sm1, sm2)(randXTotalcoord, randYTotalcoord);
  }

  auto rootT2 = high_resolution_clock::now();
  duration<double, std::milli> rootTime = rootT2 - rootT1;
  std::cout << "sMatrixSimilarity: " << rootTime.count() << "ms\n\n";

  auto tripleInitT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopTripleInit<m1Rows, m1ColumnsM2RowsColumns>(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto tripleInitT2 = high_resolution_clock::now();
  duration<double, std::milli> tripleInitTime = tripleInitT2 - tripleInitT1;
  std::cout << "matrixMultFastLoopTripleInit: " << tripleInitTime.count() << "ms\n\n";

  auto oldT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultEigen<m1Rows, m1ColumnsM2RowsColumns>(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto oldT2 = high_resolution_clock::now();
  duration<double, std::milli> oldTime = oldT2 - oldT1;
  std::cout << "matrixMultEigen: " << oldTime.count() << "ms\n\n";

  return 0;
}
