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

ll n,x;
vector<ll> v;

/* add your algorithm here */

ll gcd(ll x, ll y) {
  if (y > x) swap(x,y);
  if (y == 0) return x;
  return gcd(y, x%y);
}

int main() {
  cin >> n >> x;
  if (n == 1) {
    ll t;
    cin >> t;
    cout << abs(x - t) << endl;
    return 0;
  }

  rep(i,n) {
    ll t; cin >> t;
    v.pb(abs(t - x));
  }

  ll ans = 0;

  for (auto itr = v.begin(); itr != v.end(); ++itr) {
    ans = gcd(*itr, ans);
  }

  cout << ans << endl;
}
