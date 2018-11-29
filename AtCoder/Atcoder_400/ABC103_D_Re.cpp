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

typedef pair<ll,ll> pl;

int main() {
  ll n,m;
  cin >> n >> m;

  vector<pl> p;

  rep(i,m) {
    ll a,b; cin >> a >> b;
    p.pb(make_pair(a,b));
  }

  sort(p.begin(), p.end(), [](const pl& x, pl& y) {return x.second < y.second;});


  ll tmp = 0, ans = 0;
  rep(i,m) {
    if (p[i].first >= tmp) {
      tmp = p[i].second;
      ans++;
    }
  }

  cout << ans << endl;

}
