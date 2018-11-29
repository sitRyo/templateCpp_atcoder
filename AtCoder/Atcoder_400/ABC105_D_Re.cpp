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
#define rep(i,n) for(ll i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll n,m;
vector<ll> a;

/* add your algorithm here */

int main() {
  cin >> n >> m;
  ll x;
  rep(i,n) {
    cin >> x;
    a.pb(x);
  }

  ll sum[n+1];

  rep(i,n+1) sum[i] = 0;
  for (ll i = 0; i < m; ++i) buc[i] = 0;

  sum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    sum[i] += (sum[i-1] + a[i-1]) % m;
    buc[sum[i]]++;
  }

  ll ans = 0;
  for (ll i = 0; i < m; ++i) {
    if (i == 0) ans += buc[0];
    if (buc[i] >= 2) {
      ans += (buc[i] / 2) * buc[i] - 1;
    }
    cout << i << endl;
  }

  cout << ans << endl;
}
