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

inline int solve1(int x, int y) {
  if (x % 3 == 0) {
    return 0;
  } else {
    return y;
  }
}

inline int solve2(ll x, ll y) {
  ll res = MOD;
  for (ll i = 1; i < x; ++i) {
    ll buf1, buf2, buf3;
    buf1 = i * y;
    buf2 = (x - i) * (y / 2);
    buf3 = (x - i) * ((y + 1) / 2);


    ll sub = max(max(abs(buf1 - buf2), abs(buf1 - buf3)), abs(buf2 - buf3));
    res = min(sub, res);
  }

  return res;
}

int main() {
  ll h,w; cin >> h >> w;
  int ans = MOD;
  ans = min(ans, solve1(h,w));
  ans = min(ans, solve1(w,h));
  ans = min(ans, solve2(h,w));
  ans = min(ans, solve2(w,h));

  cout << ans << endl;
}
