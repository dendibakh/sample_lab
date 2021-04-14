#include <iostream>

int solution (int* arr, int n);

int main() {
  constexpr int N = 1000;
  int arr[N];
  for (int i = 0; i < N; i++) {
    arr[i] = i + 1;
  }

  int result = solution(arr, N);
  if (result != (N * (N + 1)) / 2) {
    std::cerr << "Validation Failed. Result = " << result << ". Expected = " << 6 << std::endl;
    return 1;
  }

  std::cout << "Validation Successful" << std::endl;
  return 0;
}
