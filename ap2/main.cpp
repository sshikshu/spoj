#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  unsigned long long t, sum, a, d, n, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y >> sum;
    n = 2 * sum / (x + y);
    d = (y - x) / (n - 5);  // n>7 guaranteed
    cout << n << endl;
    for (a = x - 2 * d; --n; a += d) {
      cout << a << " ";
    }
    cout << a << endl;
  }
}
