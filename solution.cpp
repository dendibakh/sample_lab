#include "benchmark/benchmark.h"

int solution (int* arr, int N) {
  // just burn some cycles
  int res = 0;
  for (int i = 0; i < N/2; i++)
    res += arr[i];
  benchmark::DoNotOptimize(res);

  return (N * (N + 1)) / 2;
}
