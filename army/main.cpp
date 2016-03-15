#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int t, nG, nM, largestGodzilla, largestMechazilla, temp;
  string _;
  cin >> t;
  while (t--) {
    largestGodzilla = 0;
    largestMechazilla = 0;
    cin >> nG >> nM;
    while (nG--) {
      cin >> temp;
      if (temp > largestGodzilla) {
        largestGodzilla = temp;
      }
    }
    while (nM--) {
      cin >> temp;
      if (temp > largestMechazilla) {
        largestMechazilla = temp;
      }
    }
    if (largestGodzilla < largestMechazilla) {
      cout << "MechaGodzilla" << endl;
    } else {
      cout << "Godzilla" << endl;
    }
  }
}
