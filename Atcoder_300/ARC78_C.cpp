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

ll n;

/* add your algorithm here */

int main() {
  cin >> n;
  vector<ll> a(n,0);
  vector<ll> sum(n+1, 0);
  rep(i,n) {
    cin >> a[i];
    sum[i+1] += sum[i] + a[i];
  }

  ll ans = 10e18+1;
  for (ll i = 1; i < n; ++i) {
    ll t1,t2;
    t1 = sum[i], t2 = sum.back() - t1;
    ll tmp = abs(t1-t2);
    ans = min(tmp, ans);
  }

  cout << ans << endl;
}
