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

vector<ll> a,b,c;

/* add your algorithm here */

int main() {
  ll n;
  cin >> n;

  rep(i,n) {
    ll t;
    cin >> t;
    a.pb(t);
  }

  rep(i,n) {
    ll t;
    cin >> t;
    b.pb(t);
  }

  rep(i,n) {
    ll t;
    cin >> t;
    c.pb(t);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  cout << *(a.begin()) << " " << a[0] << endl;
  cout << *(a.end()) << " " << a[n] << endl;

  ll ans = 0;

  rep(i,n) {
    ll tar = b[i];
    ll ta, tc;
    tc = c.end() - upper_bound(c.begin(), c.end(), tar);
    ta = lower_bound(a.begin(), a.end(), tar) - a.begin();

    ans += ta * tc;
  }

  cout << ans << endl;
}
