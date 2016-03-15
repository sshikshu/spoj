#include <algorithm>
#include <array>
#include <iterator>
#include <iostream>

using namespace std;

const int MAX_SIZE = 200000;

template <typename Iterator>
unsigned long long merge(Iterator begin, Iterator mid, Iterator end) {
  auto leftLen = distance(begin, mid);
  unsigned long long count = 0;

  vector<typename iterator_traits<Iterator>::value_type> sorted;

  Iterator left = begin, right = mid;

  while (left != mid && right != end) {
    if (less<typename iterator_traits<Iterator>::value_type>()(*left, *right)) {
      sorted.emplace_back(*left++);
    } else {
      sorted.emplace_back(*right++);
      count += (leftLen - distance(begin, left));
    }
  }

  while (left != mid) {
    sorted.emplace_back(*left++);
  }
  while (right != end) {
    sorted.emplace_back(*right++);
  }

  copy(sorted.begin(), sorted.end(), begin);

  return count;
}

template <typename Iterator>
unsigned long long inversionCount(Iterator begin, Iterator end) {
  auto len = distance(begin, end);
  if (len < 2) return 0;

  Iterator mid = next(begin, len / 2);

  return inversionCount(begin, mid) + inversionCount(mid, end) +
         merge(begin, mid, end);
}

int main(int argc, char* argv[]) {
  int i, t;
  int n;
  cin >> t;
  array<int, MAX_SIZE> arr;

  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    };
    cout << inversionCount(arr.begin(), arr.begin() + n) << endl;
  }
}
