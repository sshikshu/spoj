#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
  long long n, k, x;
  while (true) {
    cin >> n;
    if (n == -1) {
      break;
    }
    k = 12 * n - 3;
    if (k < 9) {
      cout << "N" << endl;
      continue;
    }

    if (k % 9 != 0 || k % 36 == 0) {
      cout << "N" << endl;
      continue;
    }

    x = (long long)sqrt(k);
    if (x * x != k) {
      cout << "N" << endl;
      continue;
    }

    cout << "Y" << endl;
    continue;
  }
  return 0;
}
