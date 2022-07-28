#include "benchmark/benchmark.h"
#include "eigenSimilarity.h"
#include "similarityTripleLoop.h"
#include "similarityTripleLoopInit.h"
#include "similarityTripleLoopRef.h"
#include "similarityTripleLoopRefInit.h"
#include "smatrixSimilarity.h"
#include "similarityHeader.h"

//Adds the benchmarks to the benchmark suite

#define BENCHMARK_SUITE(x)			\
	BENCHMARK(x)				\
		->Threads(1)			\
		->Repetitions(REPETITIONS)	\
		->DisplayAggregatesOnly(true) 	\
		->UseRealTime();

BENCHMARK_SUITE(eigenSimilarity);

BENCHMARK_SUITE(tripleLoopSimilarity);

BENCHMARK_SUITE(tripleLoopInitSimilarity);

BENCHMARK_SUITE(tripleLoopRefSimilarity);

BENCHMARK_SUITE(tripleLoopRefInitSimilarity);

BENCHMARK_SUITE(smatrixSimilarity);
