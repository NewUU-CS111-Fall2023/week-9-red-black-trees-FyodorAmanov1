/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; ++test_case) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    int sum = 0;
    for (int i = 0; i < N - 2; ++i) {
      int odd_size = 3;
      int min_median = INT_MAX;

      while (odd_size <= N - i - 1) {
        int median = (odd_size + 1) / 2;
        int left = i + (median - 1);
        int right = i + odd_size - 1;
        min_median = min(min_median, (A[left] + A[right]) / 2);
        odd_size += 2;
      }

      if (min_median < A[i]) {
        // Remove first occurrence of min_median
        A.erase(remove(A.begin() + i, A.end(), min_median), A.end());
        N--;
      }

      sum += A[i];
    }

    sum += A[N - 1] + A[N - 2];
    cout << sum << endl;
  }

  return 0;
}