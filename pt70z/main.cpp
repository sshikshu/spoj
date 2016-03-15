#include <iostream>
#include <cstdio>

int main() {
  // Complete the code.
  int a;
  long b;
  long long c;
  char d;
  float e;
  double f;
  std::printf("%d %ld %lld %c %f %lf", &a, &b, &c, &d, &e, &f);
  std::cout << a << std::endl
            << b << std::endl
            << c << std::endl
            << d << std::endl
            << e << std::endl
            << f << std::endl;
  return 0;
}
