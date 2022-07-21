#ifndef TRIPLE_LOOP_INIT_SIMILARITY_H
#define TRIPLE_LOOP_INIT_SIMILARITY_H

#include "../similarityImplementations.hpp"
#include "Eigen/Dense"
#include "benchmark/benchmark.h"
#include "similarityHeader.h"

static void tripleLoopInitSimilarity(benchmark::State& state)
{
  Eigen::Matrix<double, M1ROWS, M1COLUMNSM2ROWSCOLUMNS> m1 = Eigen::Matrix<double, M1ROWS, M1COLUMNSM2ROWSCOLUMNS>::Random(M1ROWS, M1COLUMNSM2ROWSCOLUMNS);
  Eigen::Matrix<double, M1COLUMNSM2ROWSCOLUMNS, M1COLUMNSM2ROWSCOLUMNS> m2 = Eigen::Matrix<double, M1COLUMNSM2ROWSCOLUMNS, M1COLUMNSM2ROWSCOLUMNS>::Random(M1COLUMNSM2ROWSCOLUMNS, M1COLUMNSM2ROWSCOLUMNS);
  Eigen::Matrix<double, M1ROWS, M1ROWS> res;

  for (auto _ : state) {
    benchmark::DoNotOptimize(res);
    res = matrixMultFastLoopTripleInit<M1ROWS, M1COLUMNSM2ROWSCOLUMNS>(m1, m2);
  }
}

#endif
