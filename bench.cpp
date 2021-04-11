#include "benchmark/benchmark.h"
#include <iostream>

int solution (int* arr, int n);

static void bench1(benchmark::State &state) {
  // problem: count sum of all the numbers up to N
  constexpr int N = 3;
  int arr[N];
  for (int i = 0; i < N; i++) {
    arr[i] = i + 1;
  }
  int result = solution(arr, N);
  if (result != 6)
    std::cerr << "Validation Failed";
  else
    std::cout << "Validation Successful";

  // benchmark
  for (auto _ : state) {
    solution(arr, N);
  }
}

// Register the function as a benchmark
BENCHMARK(bench1);

// Run the benchmark
BENCHMARK_MAIN();
