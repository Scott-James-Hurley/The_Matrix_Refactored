#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cblas.h>
#include <Eigen/Dense>
#include <Math/SMatrix.h>

//Time taken: 512.747ms
Eigen::Matrix<double, 6, 6> matrixMultCurly(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;

  const double *m1p = m1.data();
  const double *m3p = m3.data();

  return Eigen::Matrix<double, 6, 6> {
          {m1p[0] * m3p[0] + m1p[6]  * m3p[6]  + m1p[12] * m3p[12] + m1p[18] * m3p[18] + m1p[24] * m3p[24] + m1p[30] * m3p[30], m1p[1] * m3p[0] + m1p[7]  * m3p[6]  + m1p[13] * m3p[12] + m1p[19] * m3p[18] + m1p[25] * m3p[24] + m1p[31] * m3p[30], m1p[2] * m3p[0] + m1p[8]  * m3p[6]  + m1p[14] * m3p[12] + m1p[20] * m3p[18] + m1p[26] * m3p[24] + m1p[32] * m3p[30], m1p[3] * m3p[0] + m1p[9]  * m3p[6]  + m1p[15] * m3p[12] + m1p[21] * m3p[18] + m1p[27] * m3p[24] + m1p[33] * m3p[30], m1p[4] * m3p[0] + m1p[10] * m3p[6]  + m1p[16] * m3p[12] + m1p[22] * m3p[18] + m1p[28] * m3p[24] + m1p[34] * m3p[30], m1p[5] * m3p[0] + m1p[11] * m3p[6]  + m1p[17] * m3p[12] + m1p[23] * m3p[18] + m1p[29] * m3p[24] + m1p[35] * m3p[30]},
          {m1p[0] * m3p[1] + m1p[6]  * m3p[7]  + m1p[12] * m3p[13] + m1p[18] * m3p[19] + m1p[24] * m3p[25] + m1p[30] * m3p[31], m1p[1] * m3p[1] + m1p[7]  * m3p[7]  + m1p[13] * m3p[13] + m1p[19] * m3p[19] + m1p[25] * m3p[25] + m1p[31] * m3p[31], m1p[2] * m3p[1] + m1p[8]  * m3p[7]  + m1p[14] * m3p[13] + m1p[20] * m3p[19] + m1p[26] * m3p[25] + m1p[32] * m3p[31], m1p[3] * m3p[1] + m1p[9]  * m3p[7]  + m1p[15] * m3p[13] + m1p[21] * m3p[19] + m1p[27] * m3p[25] + m1p[33] * m3p[31], m1p[4] * m3p[1] + m1p[10] * m3p[7]  + m1p[16] * m3p[13] + m1p[22] * m3p[19] + m1p[28] * m3p[25] + m1p[34] * m3p[31], m1p[5] * m3p[1] + m1p[11] * m3p[7]  + m1p[17] * m3p[13] + m1p[23] * m3p[19] + m1p[29] * m3p[25] + m1p[35] * m3p[31]},
          {m1p[0] * m3p[2] + m1p[6]  * m3p[8]  + m1p[12] * m3p[14] + m1p[18] * m3p[20] + m1p[24] * m3p[26] + m1p[30] * m3p[32], m1p[1] * m3p[2] + m1p[7]  * m3p[8]  + m1p[13] * m3p[14] + m1p[19] * m3p[20] + m1p[25] * m3p[26] + m1p[31] * m3p[32], m1p[2] * m3p[2] + m1p[8]  * m3p[8]  + m1p[14] * m3p[14] + m1p[20] * m3p[20] + m1p[26] * m3p[26] + m1p[32] * m3p[32], m1p[3] * m3p[2] + m1p[9]  * m3p[8]  + m1p[15] * m3p[14] + m1p[21] * m3p[20] + m1p[27] * m3p[26] + m1p[33] * m3p[32], m1p[4] * m3p[2] + m1p[10] * m3p[8]  + m1p[16] * m3p[14] + m1p[22] * m3p[20] + m1p[28] * m3p[26] + m1p[34] * m3p[32], m1p[5] * m3p[2] + m1p[11] * m3p[8]  + m1p[17] * m3p[14] + m1p[23] * m3p[20] + m1p[29] * m3p[26] + m1p[35] * m3p[32]},
          {m1p[0] * m3p[3] + m1p[6]  * m3p[9]  + m1p[12] * m3p[15] + m1p[18] * m3p[21] + m1p[24] * m3p[27] + m1p[30] * m3p[33], m1p[1] * m3p[3] + m1p[7]  * m3p[9]  + m1p[13] * m3p[15] + m1p[19] * m3p[21] + m1p[25] * m3p[27] + m1p[31] * m3p[33], m1p[2] * m3p[3] + m1p[8]  * m3p[9]  + m1p[14] * m3p[15] + m1p[20] * m3p[21] + m1p[26] * m3p[27] + m1p[32] * m3p[33], m1p[3] * m3p[3] + m1p[9]  * m3p[9]  + m1p[15] * m3p[15] + m1p[21] * m3p[21] + m1p[27] * m3p[27] + m1p[33] * m3p[33], m1p[4] * m3p[3] + m1p[10] * m3p[9]  + m1p[16] * m3p[15] + m1p[22] * m3p[21] + m1p[28] * m3p[27] + m1p[34] * m3p[33], m1p[5] * m3p[3] + m1p[11] * m3p[9]  + m1p[17] * m3p[15] + m1p[23] * m3p[21] + m1p[29] * m3p[27] + m1p[35] * m3p[33]},
          {m1p[0] * m3p[4] + m1p[6]  * m3p[10] + m1p[12] * m3p[16] + m1p[18] * m3p[22] + m1p[24] * m3p[28] + m1p[30] * m3p[34], m1p[1] * m3p[4] + m1p[7]  * m3p[10] + m1p[13] * m3p[16] + m1p[19] * m3p[22] + m1p[25] * m3p[28] + m1p[31] * m3p[34], m1p[2] * m3p[4] + m1p[8]  * m3p[10] + m1p[14] * m3p[16] + m1p[20] * m3p[22] + m1p[26] * m3p[28] + m1p[32] * m3p[34], m1p[3] * m3p[4] + m1p[9]  * m3p[10] + m1p[15] * m3p[16] + m1p[21] * m3p[22] + m1p[27] * m3p[28] + m1p[33] * m3p[34], m1p[4] * m3p[4] + m1p[10] * m3p[10] + m1p[16] * m3p[16] + m1p[22] * m3p[22] + m1p[28] * m3p[28] + m1p[34] * m3p[34], m1p[5] * m3p[4] + m1p[11] * m3p[10] + m1p[17] * m3p[16] + m1p[23] * m3p[22] + m1p[29] * m3p[28] + m1p[35] * m3p[34]},
          {m1p[0] * m3p[5] + m1p[6]  * m3p[11] + m1p[12] * m3p[17] + m1p[18] * m3p[23] + m1p[24] * m3p[29] + m1p[30] * m3p[35], m1p[1] * m3p[5] + m1p[7]  * m3p[11] + m1p[13] * m3p[17] + m1p[19] * m3p[23] + m1p[25] * m3p[29] + m1p[31] * m3p[35], m1p[2] * m3p[5] + m1p[8]  * m3p[11] + m1p[14] * m3p[17] + m1p[20] * m3p[23] + m1p[26] * m3p[29] + m1p[32] * m3p[35], m1p[3] * m3p[5] + m1p[9]  * m3p[11] + m1p[15] * m3p[17] + m1p[21] * m3p[23] + m1p[27] * m3p[29] + m1p[33] * m3p[35], m1p[4] * m3p[5] + m1p[10] * m3p[11] + m1p[16] * m3p[17] + m1p[22] * m3p[23] + m1p[28] * m3p[29] + m1p[34] * m3p[35], m1p[5] * m3p[5] + m1p[11] * m3p[11] + m1p[17] * m3p[17] + m1p[23] * m3p[23] + m1p[29] * m3p[29] + m1p[35] * m3p[35]},
  };
}

//Time taken: 457.002ms
ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> sMatrixSimilarity(const ROOT::Math::SMatrix<double, 6, 6> &m2, const ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> &m1)
{
  return ROOT::Math::Similarity(m2, m1);
}
//Time taken: 3703.75ms
void openBlasMatrixMultTrans(const double* m1, const double* m2, double* m3) {
  double m4[36] = {};
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 6, 6, 6, 1, m1, 6, m2, 6, 0, m4, 6);
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans, 6, 6, 6, 1, m4, 6, m1, 6, 1, m3, 6);
}

//Time taken: 676.414ms
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

//Time taken: 541.569ms
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

//Time taken: 380.66ms
Eigen::Matrix<double, 6, 6> matrixMultFastLoopTripleInit(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
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
      *(resultPtr + ResultPtrIndex) = 0;

      for (int offset = 0; offset < 31; offset = offset + 6)
      {
        *(resultPtr + ResultPtrIndex) += *(m1Ptr + rowIndex + offset) * *(m3Ptr + columnIndex + offset);
      }

      ResultPtrIndex++;
    }
  }

  return result;
}

//Time taken: 536.414ms
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

//Time taken: 380.66ms
Eigen::Matrix<double, 6, 6> matrixMultFastLoopTripleRefInit(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
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
      resultData[ResultDataIndex] = 0;

      for (int offset = 0; offset < 31; offset = offset + 6)
      {
        resultData[ResultDataIndex] += m1Data[rowIndex + offset] * m3Data[columnIndex + offset];
      }

      ResultDataIndex++;
    }
  }

  return result;
}

//Time taken: 670.436ms
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

//Time taken: 426.406ms
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

//Time taken: 334.026ms
Eigen::Matrix<double, 6, 6> matrixMultEigen(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
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

  auto pointerCurlyT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultCurly(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto pointerCurlyT2 = high_resolution_clock::now();
  duration<double, std::milli> PointerCurlyTime = pointerCurlyT2 - pointerCurlyT1;
  std::cout << "matrixMultCurly: " << PointerCurlyTime.count() - sampleTime.count() << "ms\n\n";

  auto loopT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoop(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto loopT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTime = loopT2 - loopT1;
  std::cout << "matrixMultFastLoop: " << loopTime.count() - sampleTime.count() << "ms\n\n";

  auto loopTheTripleT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopTheTriple(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto loopTheTripleT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTheTripleTime = loopTheTripleT2 - loopTheTripleT1;
  std::cout << "matrixMultFastLoopTheTriple: " << loopTheTripleTime.count() - sampleTime.count() << "ms\n\n";

  auto loopAccessT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopAccess(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto loopAccessT2 = high_resolution_clock::now();
  duration<double, std::milli> loopAccessTime = loopAccessT2 - loopAccessT1;
  std::cout << "matrixMultFastLoopAccess: " << loopAccessTime.count() - sampleTime.count() << "ms\n\n";

  auto loopRefT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopRef(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto loopRefT2 = high_resolution_clock::now();
  duration<double, std::milli> loopRefTime = loopRefT2 - loopRefT1;
  std::cout << "matrixMultFastLoopRef: " << loopRefTime.count() - sampleTime.count() << "ms\n\n";

  auto loopTripleRefT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopTripleRef(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto loopTripleRefT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTripleRefTime = loopTripleRefT2 - loopTripleRefT1;
  std::cout << "matrixMultFastLoopTripleRef: " << loopTripleRefTime.count() - sampleTime.count() << "ms\n\n";

  auto loopTripleRefInitT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopTripleRefInit(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto loopTripleRefInitT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTripleRefInitTime = loopTripleRefInitT2 - loopTripleRefInitT1;
  std::cout << "matrixMultFastLoopTripleRefInit: " << loopTripleRefInitTime.count() - sampleTime.count() << "ms\n\n";

  auto rootT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(randXcoord, randYcoord) = (double)rand();
    total += sMatrixSimilarity(sm1, sm2)(randXTotalcoord, randYTotalcoord);
  }

  auto rootT2 = high_resolution_clock::now();
  duration<double, std::milli> rootTime = rootT2 - rootT1;
  std::cout << "sMatrixSimilarity: " << rootTime.count() - smatrixSampleTime.count() << "ms\n\n";

  auto tripleInitT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultFastLoopTripleInit(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto tripleInitT2 = high_resolution_clock::now();
  duration<double, std::milli> tripleInitTime = tripleInitT2 - tripleInitT1;
  std::cout << "matrixMultFastLoopTripleInit: " << tripleInitTime.count() - sampleTime.count() << "ms\n\n";

  auto blasT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    double m3[36] = {};
    m1(randXcoord, randYcoord) = (double)rand();
    openBlasMatrixMultTrans(m1.data(), m2.data(), m3);
    total += m3[randXTotalcoord];
  }

  auto blasT2 = high_resolution_clock::now();
  duration<double, std::milli> blasTime = blasT2 - blasT1;
  std::cout << "blas: " << blasTime.count()  - sampleTime.count() << "ms\n\n";

  auto oldT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(randXcoord, randYcoord) = (double)rand();
    total += matrixMultEigen(m1, m2)(randXTotalcoord, randYTotalcoord);
  }

  auto oldT2 = high_resolution_clock::now();
  duration<double, std::milli> oldTime = oldT2 - oldT1;
  std::cout << "matrixMultEigen: " << oldTime.count() - sampleTime.count() << "ms\n\n";

  return 0;
}
