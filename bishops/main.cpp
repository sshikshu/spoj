#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

const int MAX_SIZE = 9;
const long long MAX_NUMBER = std::pow(10, MAX_SIZE);

template <typename T>
std::ostream &operator<<(std::ostream &outputStream, const std::vector<T> &v) {
  outputStream << '[';
  for (auto x : v) {
    outputStream << x << ", ";
  }
  if (!v.empty()) {
    outputStream << "\b\b";
  }
  outputStream << "]";
  return outputStream;
}

class BigInteger {
 private:
  void postOperation() {
    for (auto it = this->integer.begin(); it != this->integer.end() - 1;
         it += 1) {
      if (*it > MAX_NUMBER) {
        *std::next(it) += *it / MAX_NUMBER;
        *it = *it % MAX_NUMBER;
      } else if (*it < 0) {
        *std::next(it) -= *it / MAX_NUMBER + 1;
        *it = MAX_NUMBER + *it % MAX_NUMBER;
      }
    }
    int msb = *(this->integer.end() - 1);
    if (msb > MAX_NUMBER) {
      this->integer.resize(this->integer.size() + 1);
      *(this->integer.end() - 2) = msb % MAX_NUMBER;
      *(this->integer.end() - 1) = msb / MAX_NUMBER;
    }
  }

 public:
  std::vector<long long> integer;
  BigInteger(std::string integer) {
    const std::string whitespaces = " \t\n\r\f\v";
    int begin, end;
    // trim
    integer.erase(0, integer.find_first_not_of(whitespaces));
    integer.erase(integer.find_last_not_of(whitespaces) + 1);
    int msb = integer.length() % MAX_SIZE;
    this->integer.resize(integer.length() / MAX_SIZE + (msb != 0) + 1);
    if (msb) {
      this->integer.emplace_back(stoll(integer.substr(0, msb)));
    }
    for (std::string::iterator it =
             integer.begin() + integer.length() % MAX_SIZE;
         it != integer.end(); it += MAX_SIZE) {
      begin = std::distance(integer.begin(), it);
      this->integer.emplace_back(stoll(integer.substr(begin, MAX_SIZE)));
    }
    std::reverse(this->integer.begin(), this->integer.end());
    // std::cout << this->integer << std::endl;
  }

  BigInteger(long long integer) {
    this->integer.emplace_back(integer);
    this->integer.emplace_back(0);
  }

  BigInteger &operator+=(const BigInteger &rhs) {
    if (rhs.integer.size() > this->integer.size()) {
      this->integer.resize(rhs.integer.size() + 1);
    }
    std::transform(rhs.integer.begin(), rhs.integer.end(),
                   this->integer.begin(), this->integer.begin(),
                   [](auto a, auto b) { return a + b; });
    // std::cout << this->integer << std::endl;
    this->postOperation();
    return *this;
  }

  BigInteger &operator+=(const long long &rhs) {
    *(this->integer.begin()) += rhs;
    this->postOperation();
    return *this;
  }

  BigInteger &operator-=(const long long &rhs) {
    return this->operator+=(-rhs);
  }

  BigInteger &operator-=(const BigInteger &rhs) {
    if (rhs.integer.size() > this->integer.size()) {
      this->integer.resize(rhs.integer.size() + 1);
    }
    std::transform(rhs.integer.begin(), rhs.integer.end(),
                   this->integer.begin(), this->integer.begin(),
                   [](auto a, auto b) { return a - b; });
    this->postOperation();
    return *this;
  }

  BigInteger &operator*=(const long long &rhs) {
    std::transform(this->integer.begin(), this->integer.end(),
                   this->integer.begin(), [rhs](auto x) { return x * rhs; });
    this->postOperation();
    return *this;
  }
};

std::ostream &operator<<(std::ostream &outputStream, const BigInteger &bigInt) {
  bool numberStarted = false;
  for (auto it = bigInt.integer.rbegin(); it != bigInt.integer.rend();
       it += 1) {
    if (*it || numberStarted) {
      if (numberStarted) {
        outputStream << std::setw(MAX_SIZE) << std::setfill('0');
      }
      outputStream << *it;
      numberStarted = true;
    }
  }
  if (!numberStarted) {
    outputStream << 0;
  }
  return outputStream;
}

const BigInteger &operator+(BigInteger lhsInt, const long long &rhsInt) {
  return lhsInt += rhsInt;
}

const BigInteger &operator+(BigInteger lhsInt, const BigInteger &rhsInt) {
  return lhsInt += rhsInt;
}

const BigInteger &operator+(const long long &lhsInt, BigInteger rhsInt) {
  return rhsInt += lhsInt;
}

const BigInteger &operator-(BigInteger lhsInt, const long long &rhsInt) {
  return lhsInt -= rhsInt;
}

const BigInteger &operator-(BigInteger lhsInt, const BigInteger &rhsInt) {
  return lhsInt -= rhsInt;
}

const BigInteger &operator-(const long long lhsInt, const BigInteger &rhsInt) {
  return BigInteger(lhsInt) -= rhsInt;
}

const BigInteger &operator*(BigInteger lhsInt, const long long &rhsInt) {
  return lhsInt *= rhsInt;
}

const BigInteger &operator*(const long long &lhsInt, BigInteger rhsInt) {
  return rhsInt *= lhsInt;
}

bool operator==(const BigInteger &lhsInt, const BigInteger &rhsInt) {
  int size = std::max(lhsInt.integer.size(), rhsInt.integer.size());
  auto vector1 = lhsInt.integer;
  auto vector2 = rhsInt.integer;
  vector1.resize(size);
  vector2.resize(size);
  return std::equal(vector1.begin(), vector1.end(), vector2.begin());
}

bool operator==(const BigInteger &lhsInt, const long long &rhsInt) {
  long long lhs = *lhsInt.integer.begin();
  return lhs == rhsInt;
}

bool operator==(const long long &lhsInt, const BigInteger &rhsInt) {
  long long rhs = *rhsInt.integer.begin();
  return rhs == lhsInt;
}

int main(int argc, char *argv[]) {
  std::string s;
  while (std::getline(std::cin, s)) {
    BigInteger integer(s);
    std::cout << ((1 == integer) ? 1 : 2 * integer - 2) << " " << std::endl;
  }

  return 0;
}
