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
#include <map>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  ll h,w,n;
  cin >> h >> w >> n;
  map<pair<ll,ll>, ll> mp;

  rep(i,n) {
    ll x,y; cin >> y >> x;
    rep(j,3)rep(k,3) {
      if (y-j <= h-2 and x-k <= w-2 and y-j >= 1 and x-k >= 1) {
        mp[make_pair(y-j, x-k)]++;
      }
    }
  }

  ll cnt[11];
  rep(i,11) cnt[i] = 0;
  ll len = 0;

  for (auto itr : mp) {
    if (itr.second > 9) {
      cnt[10]++;
      continue;
    }
    cnt[itr.second]++;
    len++;
  }

  ll zero = (h-2) * (w-2) - len;
  cnt[0] = zero;

  rep(i,10) cout << cnt[i] << endl;
}
