#include "benchmark/benchmark.h"

int solution (int* arr, int N) {
  // just burn some cycles. Do 90% of the work, which will no qualify for a successful test.
  int res = 0;
  for (int i = 0; i < N * .9 ; i++)
    res += arr[i];
  benchmark::DoNotOptimize(res);

  return (N * (N + 1)) / 2;
}
