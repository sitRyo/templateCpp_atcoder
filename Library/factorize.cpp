#include <bits/stdc++.h>

template<typename T>
map<T, long long> factorize(T x) {
  map<T, long long> res;
  for (long long i = 2; i * i <= x; ++i) {
    while (x % i == 0) {
      x /= i;
      res[i] += 1;
    }
  }
  if (x != 1) res[x]++;
  return res;
}

template<typename T>
long long factorize_num(T x, T num) {
  long long res = 0;
  while (x % num == 0) {
    res += 1;
    x /= num;
  }
  return res;
}
