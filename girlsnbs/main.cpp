#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
  double g, b;
  while (true) {
    cin >> g >> b;
    if (g < 0 && b < 0) {
      break;
    }
    cout << ceil(max(g, b) / (min(g, b) + 1)) << endl;
  }
  return 0;
}
