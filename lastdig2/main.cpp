#include <array>
#include <iostream>
#include <string>

int main() {
  std::string temp;
  int t, a;
  unsigned long long b;
  std::array<int, 4> lsb;
  std::cin >> t;
  while (t--) {
    std::cin.clear();
    std::cin >> temp >> b;
    a = temp.back() - '0';
    if (b == 0) {
      a = 1;
    }
    lsb.fill(a);
    b %= 4;
    if (a == 2) {
      lsb = {6, 2, 4, 8};
    } else if (a == 3) {
      lsb = {1, 3, 9, 7};
    } else if (a == 4) {
      lsb = {6, 4, 6, 4};
    } else if (a == 7) {
      lsb = {1, 7, 9, 3};
    } else if (a == 8) {
      lsb = {6, 8, 4, 2};
    } else if (a == 9) {
      lsb = {1, 9, 1, 9};
    }
    std::cout << lsb[b] << std::endl;
  }
  return 0;
}
