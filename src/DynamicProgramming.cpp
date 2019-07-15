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