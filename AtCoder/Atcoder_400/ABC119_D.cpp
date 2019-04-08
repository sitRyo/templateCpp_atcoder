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


void chmin(ll &a, ll b) { if (a > b) a = b; }

template<class T> int former(const vector<T> &v, T x) {
  return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

template<class T> int latter(const vector<T> &v, T x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
  int a,b,q; cin >> a >> b >> q;
  vector<ll> s(a), t(b);

  rep(i,a) cin >> s[i];
  rep(i,b) cin >> t[i];

  s.push_back(INF); s.push_back(-INF); sorti(s);
  t.push_back(INF); t.push_back(-INF); sorti(t);

  for (int tt = 0; tt < q; ++tt) {
    ll x;
    cin >> x;
    ll res = INF;

    for (int i = 0; i < 2; ++i) {
      ll first = (i ? s[former(s, x)] : s[latter(s, x)]);
      for (int j = 0; j < 2; ++j) {
        ll second = (j ? t[former(t, first)] : t[latter(t, first)]);
        chmin(res, abs(x - first) + abs(first - second));
      }
    }

    for (int i = 0; i < 2; ++i) {
      ll first = (i ? t[former(t, x)] : t[latter(t, x)]);
      for (int j = 0; j < 2; ++j) {
        ll second = (j ? s[former(s, first)] : t[latter(s, first)]);
        chmin(res, abs(x - first) + abs(first - second));
      }
    }

    cout << res << endl;
  }
}
