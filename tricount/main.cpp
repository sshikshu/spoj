#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << (2*n*n*n+5*n*n+2*n-n%2)/8 << endl;
  }
}
