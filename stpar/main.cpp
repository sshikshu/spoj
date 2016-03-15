#include <iostream>
#include <array>

using namespace std;

int main(int argc, char *argv[]) {
  int n, mobile, arranged, i, firstInSideStreet = -1;
  const int limit = 1000;
  array<int, limit> lovemobiles;
  array<int, limit> sideStreet;
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    arranged = 0;
    firstInSideStreet = -1;
    sideStreet.fill(0);
    lovemobiles.fill(0);
    for (i = 0; i < n; ++i) {
      cin >> lovemobiles[i];
    }

    for (int lovemobile : lovemobiles) {
      if (lovemobile == 0) {
        break;
      }
      if (lovemobile == arranged + 1) {
        ++arranged;
      }
      //cout << lovemobile << " " << arranged << " ";
      if (firstInSideStreet != -1) {
        while (sideStreet[firstInSideStreet] == arranged + 1) {
          ++arranged;
          --firstInSideStreet;
        }
        //cout << firstInSideStreet << " " << sideStreet[firstInSideStreet];
      }
      //cout << endl;
      if (lovemobile > arranged) {
        sideStreet[++firstInSideStreet] = lovemobile;
      }
    }

    if (firstInSideStreet == -1) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
