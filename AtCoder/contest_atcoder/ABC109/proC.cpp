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

ll n,q;
vector<ll> x;
ll l,h;
ll mmin = 10e9 + 1;

/* add your algorithm here */

ll gcd(ll m, ll n);

ll gcd (ll m, ll n) {
  if (m < n) return gcd(n,m);
  if (n == 0) return m;

  return gcd(n, (m%n));
}

int main() {
  cin >> n >> q;
  if (n == 1) {
    ll a;
    cin >> a;
    cout << abs(a - q) << endl;
    return 0;
  }
  rep(i,n) {
    ll t;
    cin >> t;
    x.pb(abs(t-q));
  }

  ll d;

  sort(x.begin(), x.end());

  d = x[0];
  for (int i = 1; i < n; ++i) {
    d = gcd(x[i], d);
  }

  cout << d << endl;
}
