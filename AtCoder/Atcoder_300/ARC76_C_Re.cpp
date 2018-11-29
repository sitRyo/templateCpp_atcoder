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
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll n,m;

/* add your algorithm here */

// 階乗を計算 (MODあり)
ll factorial_mod(ll n) {
  ll ans = 1;
  for (ll i = n; i > 0; --i) {
    ans = (ans % MOD) * (i % MOD) % MOD;
  }
  return ans;
}

int main() {
  cin >> n >> m;
  if (abs(n-m) > 1) {
    cout << 0 << endl;
    return 0;
  }

  ll res;

  if (abs(n-m) == 1) {
    res = (factorial_mod(n) * factorial_mod(m)) % MOD;
    cout << res << endl;
  } else {
    res = (factorial_mod(n) * factorial_mod(n)) % MOD;
    res *= 2;
    res %= MOD;
    cout << res << endl;
  }
}
