#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {
  long long t, r;
  std::cin >> t;
  for (int i = 0; i < t; i += 1) {
    std::cin >> r;
    std::cout << "Case " << i + 1 << ": " << std::fixed << std::setprecision(2)
              << 4 * r * r + 0.25 << std::endl;
  }
  return 0;
}
