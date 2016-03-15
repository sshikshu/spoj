#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

constexpr double pi() { return acos(-1); }

int main(int argc, char *argv[]) {
  double x;
  while (true) {
    cin >> x;
    if (x == 0) {
      break;
    }
    cout << fixed << setprecision(2) << (x * x) / 2 / pi() << endl;
  }
}
