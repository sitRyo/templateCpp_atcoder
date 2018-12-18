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
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n,k;
  cin >> n >> k;
  vector<ll> a, part;
  rep(i,n) {
    ll t; cin >> t; a.pb(t);
  }
  for (int i = 0; i < n; ++i) {
    ll tmp = 0;
    for (int j = i; j < n; ++j) {
      tmp += a[j];
      part.pb(tmp);
    }
  }

  vector<ll> tw;
  ll po = 1;
  for (int i = 0; i <= 39; ++i) {
    tw.pb(po);
    po *= 2;
  }

  vector<ll> ans = part;
  ll res = 0;
  for (int i = 39; i >= 0; --i) {
    vector<ll> tm;
    ll cnt = 0;
    for (auto itr : ans) {
      ll ttt = itr & tw[i];
      if (ttt == tw[i]) {
        tm.pb(itr);
        cnt++;
      }
    }
    if (cnt >= k) {
      ans = tm;
      res += tw[i];
    }
  }

  cout << res << endl;
}
