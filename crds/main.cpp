#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  const int limit = 1000007;
  int t;
  long long n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << (((3 * n * n + n)) / 2) % limit << endl;
  }
  return 0;
}
