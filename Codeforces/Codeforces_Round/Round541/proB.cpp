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
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  ll n;
  cin >> n;

  vector<pair<ll,ll> > pa(n);
  rep(i,n) {
    ll a,b;
    scanf("%lld %lld", &a, &b);
    pa[i] = make_pair(a,b);
  }

  ll x = 0, y = 0, nx, ny, ans = 0, now = -1;
  int cnt = 0;
  map<int,bool> mp;
  rep(i,n) {
    nx = pa[i].first, ny = pa[i].second;
    for (int j = x; j <= min(nx,ny); ++j) {
      if (!mp[j]) ans += 1;
      mp[j] = true;      
    }
    x = nx, y = ny;
  }
  if (cnt > 0) ans += 1;
  cout << ans << endl;
}
