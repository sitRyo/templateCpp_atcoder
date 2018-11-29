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

ll pow_mod(ll x, ll num) {
  ll p = 1;
  for (int i = 1; i <= num; ++i) {
    p *= x;
    p %= MOD;
  }

  return p;
}

int main() {
  ll n; cin >> n;

  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    int p = i, q = (int)floor((double) n / p);
    ll pw, qw, tmp;

    pw = pow_mod(p,10);
    qw = pow_mod(q,10);
    if (p != 1) pw = pw - pow_mod(p-1, 10) + MOD;


    tmp = ((pw % MOD) * (qw % MOD)) % MOD;
    res = ((res % MOD) + tmp) % MOD;
  }

  cout << res << endl;
}
