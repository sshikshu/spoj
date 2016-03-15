#include <iostream>

int main(int argc, char *argv[]) {
  long n, squareOfDigits, digit, t = 1;
  std::cin >> n;
  while (true) {
    squareOfDigits = 0;
    for (; n != 0; n /= 10) {
      digit = n % 10;
      squareOfDigits += digit * digit;
    }
    if (squareOfDigits == 4) {
      std::cout << -1 << std::endl;
      break;
    } else if (squareOfDigits == 1) {
      std::cout << t << std::endl;
      break;
    }
    t += 1;
    n = squareOfDigits;
  }
  return 0;
}
