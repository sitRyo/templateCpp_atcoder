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

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

vector<ll> a;

template<typename T>
map<T, long long> factorize(T x) {
  map<T, long long> res;
  for (ll i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      res[i] = 1;
      res[x / i] = 1;
    }
  }
  return res;
}

int main() {
  ll n,p; cin >> n >> p;
  ll res = 1;

  if (n == 1) {
    cout << p << endl;
    return 0;
  }
  if (p <= n) {
    cout << 1 << endl;
    return 0;
  }
  map<ll, ll> mp = factorize(p);
  for (auto itr : mp) {
    ll test = itr.first;
    ll tar = itr.first;
    ll cpy = p / tar, cnt = 1;
    
    if (p / tar < tar) {
      break;
    }

    if (tar == 1) continue;

    while(true) {
      if (cpy % tar == 0 and cpy > 0) cnt++;
      else {
        break;
      }
      test *= tar;
      cpy /= tar;
    }

    // cout << cnt << endl;

    if (cpy != 0) {
      test *= cpy;
    }

    // cout << test << endl;

    if (cnt >= n and test == p) {
      res = tar;
    }
  }

  cout << res << endl;
}
