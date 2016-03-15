#include <array>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  const int MAX_LENGTH = 2000;
  int t, i, j;
  string a, b;
  array<array<int, MAX_LENGTH + 1>, MAX_LENGTH + 1> dp;
  cin >> t;
  for (i = 0; i < MAX_LENGTH + 1; i++) {
    dp[i][0] = i;
    dp[0][i] = i;
  }
  while (t--) {
    cin >> a >> b;
    for (i = 1; i < a.length() + 1; i++) {
      for (j = 1; j < b.length() + 1; j++) {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
      }
    }
    cout << dp[a.length()][b.length()] << endl;
  }
  return 0;
}
