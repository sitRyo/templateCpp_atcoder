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

ll pow_10 (ll x) {
  ll tmp = 1;
  rep(i,10) {
    tmp *= x;
    tmp %= MOD;
  }
  return tmp;
}

int main() {
  ll n; cin >> n;
  ll res = 0;
  for (int p = 1; p <= n; ++p) {
    ll q = floor(n / p);
    ll pw = pow_10(p);
    ll qw = pow_10(q);
    if (p != 1) pw = pw - pow_10(p-1) + MOD;

    ll tmp = ((pw % MOD) * (qw % MOD)) % MOD;
    res = ((res % MOD) + tmp) % MOD;
  }

  cout << res << endl;
}
