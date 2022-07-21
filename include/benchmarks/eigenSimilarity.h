#ifndef EIGEN_SIMILARITY_H
#define EIGEN_SIMILAIRTY_H

#include "Eigen/Dense"
#include "benchmark/benchmark.h"
#include "similarityHeader.h"

static void eigenSimilarity(benchmark::State& state)
{
  Eigen::Matrix<double, M1ROWS, M1COLUMNSM2ROWSCOLUMNS> m1 = Eigen::Matrix<double, M1ROWS, M1COLUMNSM2ROWSCOLUMNS>::Random(M1ROWS, M1COLUMNSM2ROWSCOLUMNS);
  Eigen::Matrix<double, M1COLUMNSM2ROWSCOLUMNS, M1COLUMNSM2ROWSCOLUMNS> m2 = Eigen::Matrix<double, M1COLUMNSM2ROWSCOLUMNS, M1COLUMNSM2ROWSCOLUMNS>::Random(M1COLUMNSM2ROWSCOLUMNS, M1COLUMNSM2ROWSCOLUMNS);
  Eigen::Matrix<double, M1ROWS, M1ROWS> res;

  for (auto _ : state) {
    benchmark::DoNotOptimize(res);
    res = m1 * m2 * m1.transpose();
  }
}
#endif
