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

// 最大公約数を求める(ユークリッドの互除法).
ll gcd (ll x, ll y) {
  if (y > x) swap(x,y);
  if (y == 0) return x;
  return gcd(x%y,y);
}

int main() {
  ll n,k; cin >> n >> k;
  vector<ll> a(n,0);
  ll mmax = 0;
  rep(i,n) {
    cin >> a[i];
    if (a[i] == k) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
    mmax = max(a[i], mmax);
  }

  if (k >= mmax) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  ll g;
  rep(i,n-1) {
    g = gcd(a[i], a[i+1]);
  }

  if (k % g == 0) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
