#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  const int LIMIT = 100000;
  int t, n, cows, start, end, mid, startDistance, cowsStalled, temp;
  bool canBeDone;
  std::vector<int> stalls;
  stalls.reserve(LIMIT);
  std::cin >> t;
  while (t--) {
    stalls.clear();
    std::cin >> n >> cows;

    while (n--) {
      std::cin >> temp;
      stalls.emplace_back(temp);
    }

    // sort stalls
    std::sort(stalls.begin(), stalls.end());

    start = stalls.front();
    end = stalls.back();
    while (end - start > 1) {
      canBeDone = false;
      mid = (start + end) / 2;
      startDistance = stalls.front();
      cowsStalled = 1;
      for (auto it = stalls.begin(); it < stalls.end() && cowsStalled <= cows;
           it += 1) {
        if (*it - startDistance >= mid) {
          cowsStalled += 1;
          startDistance = *it;
        }
      }
      // std::cout << start << ":" << mid << ":" << end << " " << cowsStalled <<
      // std::endl;
      if (cowsStalled >= cows) {
        start = mid;
      } else {
        end = mid;
      }
    }
    if (start == 1 && cowsStalled < cows) {
      start = 0;
    }
    std::cout << start << std::endl;
  }
  return 0;
}
