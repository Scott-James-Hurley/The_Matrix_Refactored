#ifndef SMATRIX_SIMILARITY_H
#define SMATRIX_SIMILAIRTY_H

#include "Math/SMatrix.h"
#include "benchmark/benchmark.h"
#include "similarityHeader.h"

static void smatrixSimilarity(benchmark::State& state)
{

  double a[M1ROWS * M1COLUMNSM2ROWSCOLUMNS];
  int triangleNumber = M1COLUMNSM2ROWSCOLUMNS * (M1COLUMNSM2ROWSCOLUMNS + 1) / 2;
  std::vector<double> v(triangleNumber);
  ROOT::Math::SMatrix<double, M1ROWS, M1COLUMNSM2ROWSCOLUMNS> res;

  for (int i = 0; i < M1ROWS * M1COLUMNSM2ROWSCOLUMNS; i++) {
    a[i] = double(rand());
  }

  for (int i = 0; i < triangleNumber; i++) {
    v[i] = double(rand());
  }

  ROOT::Math::SMatrix<double, M1ROWS, M1COLUMNSM2ROWSCOLUMNS> m1(a, M1ROWS * M1COLUMNSM2ROWSCOLUMNS);
  ROOT::Math::SMatrix<double, M1COLUMNSM2ROWSCOLUMNS, M1COLUMNSM2ROWSCOLUMNS, ROOT::Math::MatRepSym<double, M1COLUMNSM2ROWSCOLUMNS>> m2(v.begin(), v.end());

  for (auto _ : state) {
    benchmark::DoNotOptimize(res);
    res = ROOT::Math::Similarity(m1, m2);
  }
}

#endif
