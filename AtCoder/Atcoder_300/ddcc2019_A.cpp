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
#include <iomanip>
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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << std::setprecision(12);

  double ans = 0.0;
  int cnt = 0, maxcnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '-') {
      cnt = 0;
    } else {
      cnt += 1;
      maxcnt = max(maxcnt, cnt);
    }
    ans += 1.0 / (cnt + 1);
  }

  ans -= 1.0 - 1.0 / (maxcnt + 2);
  cout << ans << endl;
}
