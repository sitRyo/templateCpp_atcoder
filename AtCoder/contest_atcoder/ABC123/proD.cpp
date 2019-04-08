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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  ll x,y,z,k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];

  sortd(a);
  sortd(b);
  sortd(c);

  priority_queue<ll> que;

  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      // cout << a[i] + b[j] << endl;
      que.push(a[i] + b[j]);
    }
  }

  vector<ll> t;

  rep(i, k) {
    if (que.size() == 0) {
      break;
    }
    ll tmp = que.top();
    que.pop();
    t.push_back(tmp);
  }

  priority_queue<ll> ans;

  ll s = min<ll>(k, t.size());
  rep(i, s) {
    rep (j, z) {
      ans.push(t[i] + c[j]);
    }
  }
  rep (i,k) {
    cout << ans.top() << endl;
    ans.pop();
  }
}
