#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;

long long comb(int n, int r) {
  if (n == r) return 1;
  long long t,s,sub; t = s = sub = 1;
  for (int i = 0; i < n; ++i) {
    t *= i + 1;
  }
  for (int i = 0; i < r; ++i) {
    s *= i + 1;
  }
  for (int i = 0; i < n - r; ++i) {
    sub *= i + 1;
  }
  ll tmp = s * sub;
  return t / tmp;
}
