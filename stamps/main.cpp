#include <array>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int t, required, friends, i, borrowingFrom;
  cin >> t;
  const int limit = 1000;
  array<int, limit> stamps;
  for (int scenario = 1; scenario <= t; scenario++) {
    borrowingFrom = 0;
    cin >> required >> friends;
    stamps.fill(0);
    for (i = 0; i < friends; i++) {
      cin >> stamps[i];
    }
    sort(stamps.begin(), stamps.end(), greater<int>());
    for (int stamp : stamps) {
      if (required <= 0 || stamp == 0) {
        break;
      }
      required -= stamp;
      borrowingFrom += 1;
    }
    cout << "Scenario #" << scenario << ":" << endl;
    if (required <= 0) {
      cout << borrowingFrom << endl;
    } else {
      cout << "impossible" << endl;
    }
    cout << endl;
  }
  return 0;
}
