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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  int n, k;
  cin >> n >> k;

  ll ans = 0;
  ll cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % k == 0) cnt1 += 1;
    if (k % 2 == 0 and i % k == k / 2) cnt2 += 1;
  }
  // debug(cnt1);
  if (cnt1 or cnt2) {
    ans += cnt1 * cnt1 * cnt1;
    ans += cnt2 * cnt2 * cnt2;
  }
  cout << ans << endl;
}
