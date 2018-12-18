#include <bits/stdc++.h>

template <typename T>
vector<T> calc_portion_sum(vector<T> vec) {
  vector<T> res;
  for (long long i = 0; i < vec.size(); ++i) {
    long long sum = 0;
    for (long long j = i; j < vec.size(); ++j) {
      sum += vec[j];
      res.push_back(sum);
    }
  }
  sort(res.begin(), res.end());
  return res;
}
