#include "common.h"

int waysToClimbTopDown(int n) {
  vector<int> memo(n + 1);
  memo[0] = 1;

  for (int i = 1; i < memo.size(); ++i) {
    int minusOne = i - 1 < 0 ? 0 : memo[i - 1];
    int minusThree = i - 3 < 0 ? 0 : memo[i - 3];
    int minusFive = i - 5 < 0 ? 0 : memo[i - 5];

    memo[i] = minusOne + minusThree + minusFive;
  }

  return memo[n];
}

int waysToClimbBottomUp(int n) {
  vector<int> memo(n + 1, 0);
  memo[0] = 1;
  for (int i = 0; i < memo.size(); ++i) {
    if (i + 1 < memo.size()) {
      memo[i + 1] = memo[i + 1] + memo[i];
    }
    if (i + 3 < memo.size()) {
      memo[i + 3] = memo[i + 3] + memo[i];
    }
    if (i + 5 < memo.size()) {
      memo[i + 5] = memo[i + 5] + memo[i];
    }
  }
  return memo[n];
}

// [1, 3, 2, 5, 3, 5, 6] -> [1, 2, 3, 5, 6] of length 5.
int lengthOfLongestIncreasingSubsequence(const vector<int> &v) {
  // As you iterate through the array, you make note of the longest subsequence at index i.
  // At idx 0, it's just 1 ([1]).
  // At idx 1, it's 2 ([1, 3]).
  // At idx 2, it's still 2, because [1, 3] cannot be followed by 2. We also update our best possible answer to [1,2].
  // At idx 3, it's going to be longest subsequence of 2 (1, 2), plus 5.
  // At idx 4, it's going to be longest subsequence of 3 (1, 2, 5), minus the 5 and plus the 3.
  // At idx 5, it's going to be longest subsequence of 4 (1, 2, 3), plus 5.
  // At idx 6, 

  if (v.size() <= 1) {
    return v.size();
  }

  vector<int> memo(v.size(), -1);
  int bestLength = 0;

  memo[0] = 0;
  bestLength = 1;

  for (int i = 1; i < v.size(); ++i) {
    // If the previous index's last number is greater than this number, you replace it.
    // Best Length doesn't change
    if (v[memo[i - 1]] > v[i]) {
      memo[i] = memo[i - 1];
    } else if (v[memo[i - 1]] < v[i]) {
      // Previous index's last number is less than this number, add this number to the subsequence.
      memo[i] = i - 1;
      ++bestLength;
    }
  }

  return bestLength
}