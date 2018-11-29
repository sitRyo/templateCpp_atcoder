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
vector< pair<ll,ll> > p;

/* add your algorithm here */

int main() {
  cin >> n >> m;
  rep(i,m) {
    pair<ll, ll> pp;
    cin >> pp.first >> pp.second;
    p.pb(pp);
  }

  sort(
    p.begin(),
    p.end(),
    [](const pair<ll, ll>& x, const pair<ll, ll>& y){return x.second < y.second;}
  );

  ll ans = 0;
  ll x = -1;
  rep(i,m) {
    if (p[i].first >= x) {
      ans++;
      x = p[i].second;
    }
  }

  cout << ans << endl;
}
