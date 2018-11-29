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

#define INF 10e16
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll n,k;
vector<ll> xp,xm;

/* add your algorithm here */

int main() {
  cin >> n >> k;
  rep(i,n) {
    ll a;
    cin >> a;
    if (a >= 0) {
      xp.pb(a);
    } else {
      xm.pb(a);
    }
  }

  ll ans = INF + 1;
  sort(xm.begin(), xm.end(), greater<ll>());

  for (int i = 0; i <= k; ++i) {
    ll tmpp = 0;
    ll tmpm = 0;
    ll ta = 0;
    ll tp = k - i;
    ll tm = i;
    ll c = 0;

    if (tp != 0 && xp.size() >= tp) {
      tmpp += xp[tp-1];
      c += tp;
    }

    if (tm != 0 && xm.size() >= tm) {
      tmpm += xm[tm-1];
      c += tm;
    }

    tmpm = abs(tmpm);
    if (tmpm < tmpp) {
      ta = tmpm * 2 + tmpp;
    } else {
      ta = tmpp * 2 + tmpm;
    }

    if (c == k && ta < ans) ans = ta;
  }

  cout << ans << endl;
}
