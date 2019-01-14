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
  int n,k; cin >> n >> k;
  vector<ll> a,sub;
  for (int i = 0; i < n; ++i) {
    ll t; cin >> t;
    a.pb(t);
  }

  for (int i = 0; i < n; ++i) {
    ll sum = a[i];
    sub.pb(sum);
    for (int j = i+1; j < n; ++j) {
      sum += a[j];
      sub.pb(sum);
    }
  }
  sortd(sub);

  vector<ll> two;
  ll t = 1;
  rep(i,42) {
    two.pb(t);
    t *= 2;
  }

  vector<ll> tmp = sub;
  ll ans = 0;
  for (int i = two.size() - 1; i >= 0; --i) {
    vector<ll> now;
    ll len = tmp.size();
    for (int j = 0; j < len; ++j) {
      ll tar = tmp[j];
      ll tt = tar & two[i];
      if (tt == two[i]) {
        now.pb(tar);
      }
    }
    // cout << now.size() << endl;
    if (now.size() >= k) {
      tmp = now;
      ans += two[i];
    }
  }

  cout << ans << endl;
}
