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
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

const ll MOD = 998244353;

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

// from https://qiita.com/ofutonfuton/items/92b1a6f4a7775f00b6ae

const ll MAX = 510000;

ll fac[MAX], finv[MAX], inv[MAX];

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
ll comb(ll n, ll k) {
  if (n < k) return 1;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k]* finv[n - k] % MOD) % MOD;
}

ll hcomb(ll n,ll k){
	if(n==0 && k==0) return 1;
	return comb(n+k-1,k);
}

int main() {
  // init();
  
  ll n, a, b, k;
  cin >> n >> a >> b >> k;
  init();

  ll ans = 0;
  for (ll i = 0; i <= n; ++i) {
    ll remain = k - a * i;
    if (remain % b != 0) continue;
    ll j = remain / b;
    if (j > n) continue;
    ll tmp = comb(n, i) * comb(n, j) % MOD;
    ans += tmp;
    ans %= MOD;
  }

  cout << ans << endl;
}
