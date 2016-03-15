#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  long long gameInteger;
  int firstMove;
  cin >> gameInteger;
  firstMove = gameInteger % 10;
  if (firstMove) {
    cout << 1 << endl;
    cout << firstMove << endl;
  } else {
    cout << 2 << endl;
  }
  return 0;
}
