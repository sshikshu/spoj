#include <iostream>

int main(int argc, char *argv[]) {
  int t, rows, columns, i, j, max;
  const int LIMIT = 102;
  int dp[LIMIT][LIMIT];
  std::cin >> t;
  while (t--) {
    std::cin >> rows >> columns;
    max = 0;
    for (i = 0; i < LIMIT; i += 1) {
      for (j = 0; j < LIMIT; j += 1) {
        dp[i][j] = 0;
      }
    }
    for (i = 1; i < rows + 1; i += 1) {
      for (j = 1; j < columns + 1; j += 1) {
        std::cin >> dp[i][j];
        dp[i][j] += std::max(std::max(dp[i - 1][j + 1], dp[i - 1][j - 1]),
                             dp[i - 1][j]);
        max = std::max(max, dp[i][j]);
      }
    }
    std::cout << max << std::endl;
  }
  return 0;
}
