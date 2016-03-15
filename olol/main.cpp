#include <iostream>

int main(int argc, char *argv[]) {
  long long t, temp, accumulated = 0;
  std::cin >> t;
  while (t--) {
    std::scanf("%lld", &temp);
    accumulated ^= temp;
  }
  std::cout << accumulated << std::endl;
  return 0;
}
