#include <benchmark/benchmark.h>

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello world";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

int factorial(int n) {
    if (n == 0) return 1;
    return factorial(n -1 ) * n;
}

int factorial_tail_recursive(int n, int result = 1) {
    if (n == 0) return result;
    return factorial_tail_recursive(n - 1, result * n);
}

static void BM_Factorization(benchmark::State& state) {
    for (auto _ : state)
        factorial(100);
}
BENCHMARK(BM_Factorization);

static void BM_FactorizationTailRecursive(benchmark::State& state) {
    for (auto _ : state)
        factorial_tail_recursive(100);
}
BENCHMARK(BM_FactorizationTailRecursive);

BENCHMARK_MAIN();