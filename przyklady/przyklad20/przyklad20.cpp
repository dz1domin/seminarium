#include <benchmark/benchmark.h>
#include <map>

void BM_funkcja1(benchmark::State& s)
{
	std::map<int, int> m;

	for(const auto& _ : s)
	{
		benchmark::DoNotOptimize(m.emplace(10, 10));
	}
}

void BM_funkcja2(benchmark::State& s)
{
	std::map<int, int> m;

	for(const auto& _ : s)
	{
		benchmark::DoNotOptimize(m.try_emplace(10, 10));
	}
}

BENCHMARK(BM_funkcja1)->Repetitions(3)->Iterations(1e7);
BENCHMARK(BM_funkcja2)->Repetitions(3)->Iterations(1e7);

BENCHMARK_MAIN();
