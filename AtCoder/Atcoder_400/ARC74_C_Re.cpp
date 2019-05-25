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

#define int long long

signed main() {
  int h,w;
  cin >> h >> w;

  if (h % 3 == 0 or w % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }

  auto search = [](int w, int h) {
    int ave = w / 2;
    int res = INF;
    for (int i = 0; i <= h; ++i) {
      int mmin = 10000000;
      int mmax = -1;
      int remain_edge = h - i;
      int sa, sb, sc;
      sa = remain_edge * w;
      sb = ave * i;
      sc = (w - ave) * i;

      mmin = min({sa, sb, sc});
      mmax = max({sa, sb, sc});

      res = min({abs(mmin - mmax), res});

      sa = h * i;
      sb = ave * remain_edge;
      sb = (w - ave) * remain_edge;

      mmin = min({sa, sb, sc});
      mmax = max({sa, sb, sc});

      res = min({abs(mmin - mmax), res});
    }

    return res;
  };

  auto three = [=](int x) {
    return x;
  };

  cout << min({search(h, w), search(w, h), three(h), three(w)}) << endl;
}
