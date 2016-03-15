#include <iostream>

int main(int argc, char *argv[]) {
  int t, _, player;
  std::cin >> t;
  while (t--) {
    std::cin >> _ >> player;
    if (player == 0) {
      std::cout << "Airborne wins." << std::endl;
    } else {
      std::cout << "Pagfloyd wins." << std::endl;
    }
  }
  return 0;
}
