#include <iostream>
using namespace std;

int main() {
  long long n = 500;
  // long long n = 10;
  for (long long i = 1; i <= n; ++i) {
    if (n / i == n % i) cout << i << endl;
  }
}