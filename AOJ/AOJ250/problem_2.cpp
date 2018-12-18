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

int main() {
  int n,m; cin >> n >> m;
  while (n != 0 and m != 0) {
    vector<int> w(n),h(m);
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < m; ++i) cin >> w[i];
    vector<int> sw = calc_portion_sum(w);
    vector<int> sh = calc_portion_sum(h);
    map<ll,ll> mp;
    ll res = 0;
    for (int i = 0; i < sw.size(); ++i) {
      mp[sw[i]] += 1;
    }
    for (int i = 0; i < sh.size(); ++i) {
      res += mp[sh[i]];
    }
    cout << res << endl;
    cin >> n >> m;
  }
  return 0;
}
