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

typedef pair<int, int> P;

int main() {
  int h,w,d;
  cin >> h >> w >> d;
  map<int, P> mp;
  rep(i,h)rep(j,w) {
    int l; cin >> l;
    mp[l] = make_pair(i+1,j+1);
  }
  ll q;
  cin >> q;

  int cost[h*w+1];
  rep(i,h*w+1) cost[i] = 0;

  // mod
  for (int i = 1; i <= d; ++i) {
    for (int j = i + d; j <= h*w; j += d) {
      P p1,p2;
      int tmp;
      p1 = mp[j-d], p2 = mp[j];
      tmp = abs(p2.first - p1.first) + abs(p2.second - p1.second);
      // cout << tmp << endl;
      cost[j] = cost[j-d] + tmp;
    }
  }


  for (int i = 0; i < q; ++i) {
    ll l,r;
    cin >> l >> r;

    ll ans = cost[r] - cost[l];
    cout << ans << endl;
  }
}
