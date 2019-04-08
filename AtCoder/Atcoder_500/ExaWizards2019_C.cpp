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

typedef pair<char, char> pc;

int main() {
  int n,q;
  string s;

  cin >> n >> q;
  cin >> s;

  vector<char> t(q), d(q);
  rep(i, q) cin >> t[i] >> d[i];

  ll a, b;
  {
    auto check = [&] (int mid) {
      ll mmid = mid;
      for (int i = 0; i < q; ++i) {
        if (s[mmid] == t[i]) {
          if (d[i] == 'R') mmid += 1;
          else mmid -= 1;
        }
        // 左に落ちた
        if (mmid < 0) return true;
      }
      // 落ちない or 右に落ちる
      return false;
    };

    int l = 0, r = n - 1;
    while (r - l >= 0) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    a = l;
  }

  {
    auto check = [&] (int mid) {
      ll mmid = mid;
      for (int i = 0; i < q; ++i) {
        if (s[mmid] == t[i]) {
          if (d[i] == 'R') mmid += 1;
          else mmid -= 1;
        }
        // 右に落ちた
        if (mmid >= n) return true;
      }
      // 落ちない or 左に落ちる
      return false;
    };

    int l = 0, r = n - 1;
    while (r - l >= 0) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    b = r;
  }
  cout << a << " " << b << endl;
  if (b - a < 0) cout << 0 << endl;
  else cout << b - a + 1 << endl;
}
