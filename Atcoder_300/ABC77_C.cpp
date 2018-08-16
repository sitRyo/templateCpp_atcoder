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

ll N;
vector<ll> a, b, c;

/* add your algorithm here */

int main() {
  cin >> N;

  rep(i,N) {
    ll t;
    scanf("%lld", &t);
    a.pb(t);
  }
  rep(i,N) {
    ll t;
    scanf("%lld", &t);
    b.pb(t);
  }
  rep(i,N) {
    ll t;
    scanf("%lld", &t);
    c.pb(t);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  vector<ll>::iterator aitr = a.begin();
  vector<ll>::iterator citr = c.begin();
  ll ans = 0;

  rep(i,N) {
    ll t = b[i];
    aitr = lower_bound(aitr, a.end(), t);
    citr = upper_bound(citr, c.end(), t);
    ll x = aitr - a.begin(), y = c.end() - citr;
    // cout << x << " " << y << endl;
    ans += x * y;
  }

  cout << ans << endl;
}
