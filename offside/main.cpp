#include <algorithm>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  const int maxDistance = std::pow(10, 4);
  int a, d, i, minAttacker, minDefender1, minDefender2, temp;
  while (true) {
    minAttacker = maxDistance + 1;
    minDefender1 = maxDistance + 1;
    minDefender2 = maxDistance + 1;
    std::cin >> a >> d;
    if (a == 0 && d == 0) {
      break;
    }
    while (a--) {
      std::cin >> temp;
      minAttacker = std::min(minAttacker, temp);
    }
    while (d--) {
      std::cin >> temp;
      if (temp < minDefender1) {
        minDefender2 = minDefender1;
        minDefender1 = temp;
      } else if (temp < minDefender2) {
        minDefender2 = temp;
      }
    }
    std::cout << ((minAttacker >= minDefender2) ? "N" : "Y") << std::endl;
  }
  return 0;
}
