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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}
// 素因数分解
/*
 * [2]-> 5, [3] -> 5のとき N = 2^5 * 3^5
 */
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


#define MAX 200010

class Combination {
  using _Tp = long long;
public:
  
  _Tp fac[MAX], finv[MAX], inv[MAX];

  Combination() {
    init();
  }

  void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
      finv[i] = finv[i-1] * inv[i] % MOD;
    }
  }

  // n!! * k!^(-1) * ((n - k)!)^(-1)
  _Tp comb(_Tp n, _Tp k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k]* finv[n - k] % MOD) % MOD;
  }
};

/* END END */

int main() {
  int n,m;
  cin >> n >> m;

  Combination co;

  auto vec = factorize(m);
  ll res = 1;
  for (auto&& itr : vec) {
    auto num = itr.second;
    ll tmp = co.comb(num + n - 1, n - 1);
    res = (res * tmp) % MOD;
  }

  cout << res << endl;
}
