#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <set>

using namespace std;

const int MAX_SIZE = 200000;

class FenwickTree {
 private:
  array<long long, MAX_SIZE + 2> tree;
  unsigned int size;

  int next(int x) { return x + (-x & x); }

  int parent(int x) { return x - (-x & x); }

 public:
  FenwickTree(unsigned int size) {
    this->size = size;
    this->tree.fill(0);
  }

  void update(int index, long long value) {
    /*cout << endl << index << " " << value << endl;
    for_each(tree.begin(), tree.end(), [](auto x) { cout << x << " "; });
    cout << endl;*/
    for (; index <= this->size + 1; index = this->next(index)) {
      this->tree[index] += value;
    }
  }

  long long calculate(int index) {
    /*for_each(tree.begin(), tree.end(), [](auto x) { cout << x << " "; });
    cout << endl;*/
    long long accumulation = 0;
    for (; index > 0; index = this->parent(index)) {
      accumulation += tree[index];
    };
    return accumulation;
  }
};

int main(int argc, char *argv[]) {
  int i, t;
  long long n, inversionCount;
  array<long long, MAX_SIZE> a;
  cin >> t;
  while (t--) {
    cin >> n;
    inversionCount = 0;
    a.fill(0);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    };
    set<long long> sorted(a.begin(), a.begin() + n);
    /*for_each(sorted.begin(), sorted.end(), [](auto x) { cout << x << " "; });
    cout << endl;*/
    transform(a.begin(), a.begin() + n, a.begin(), [sorted](long long value) {
      return distance(sorted.begin(), sorted.lower_bound(value));
    });
    /*for_each(a.begin(), a.end(), [](auto x) { cout << x << " "; });
    cout << endl;*/
    FenwickTree fenwick(n);
    for (i = 0; i < n; i++) {
      fenwick.update(a[i] + 1, 1);
      /*cout << i + 1 << " " << fenwick.calculate(a[i] + 1) << " = "
           << i + 1 - fenwick.calculate(a[i] + 1) << endl;*/
      inversionCount += i + 1 - fenwick.calculate(a[i] + 1);
    }
    cout << inversionCount << endl;
  }

  return 0;
}
