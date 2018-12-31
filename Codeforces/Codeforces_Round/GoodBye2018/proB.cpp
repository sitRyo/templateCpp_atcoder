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
  pair<ll,ll> ans;
  int n; cin >> n;

  vector<pair<ll,ll> > obelisks, clues;
  map<pair<ll,ll>,bool> mp;
  rep(i,n) {
    ll a,b;
    scanf("%lld %lld", &a, &b);
    obelisks.pb(make_pair(a,b));
  }

  rep(i,n) {
    ll a,b;
    scanf("%lld %lld", &a, &b);
    clues.pb(make_pair(a,b));
    mp[make_pair(a,b)] = true;
  }

  vector<pair<ll,ll> > candT;
  pair<ll,ll> t = obelisks[0];
  rep(i,n) {
    ll a,b;
    a = t.first + clues[i].first;
    b = t.second + clues[i].second;
    candT.pb(make_pair(a,b));
  }

  if (n == 1) {
    cout << candT[0].first << " " << candT[0].second << endl;
    return 0;
  }

  bool flag = false;
  for (auto itr : candT) {
    for (int i = 1; i < n; ++i) {
      ll px,py;
      px = -obelisks[i].first + itr.first; py = -obelisks[i].second + itr.second;
      if (!mp[make_pair(px,py)]) {
        break;
      }
      if (i == n-1) {
        ans = itr;
        flag = true;
      }
    }
    if (flag) {
      break;
    }
  }

  cout << ans.first << " " << ans.second << endl;
}
