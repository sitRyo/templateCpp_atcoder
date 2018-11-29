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

// 最大公約数を求める(ユークリッドの互除法).
ll gcd (ll x, ll y) {
  if (y > x) swap(x,y);
  if (y == 0) return x;
  return gcd(x%y,y);
}


int main() {
  ll n,m;
  cin >> n >> m;
  if (m % n == 0) {
    cout << m / n << endl;
    return 0;
  }
  ll mmax = m / n, b = mmax + (m % n);
  ll ans = 1;
  for (ll i = 2; i < mmax; ++i) {
    if (m % i != 0) {
      continue;
    }

    ll tmp = i * (n-1);
    ll tt = m - tmp;
    if (tt > 0 and tt % i == 0) {
      ans = max(ans, i);
    }
  }

  cout << ans << endl;
}
