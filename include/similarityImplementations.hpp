#ifndef SIMILARITY_IMPLEMENTATIONS_HPP
#define SIMILARITY_IMPLEMENTATIONS_HPP

#include "Eigen/Dense"

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

#endif
