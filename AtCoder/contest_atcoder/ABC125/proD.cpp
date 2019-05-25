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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  ll dp[n + 1][2];
  dp[0][0] = 0;
  dp[0][1] = -INF;
  rep(i,n) cin >> a[i];
  int cursor;
  for (int i = 1; i <= n; ++i) {
    cursor = i - 1;
    dp[i][0] = max(dp[cursor][0] + a[cursor], dp[cursor][1] - a[cursor]);
    dp[i][1] = max(dp[cursor][0] - a[cursor], dp[cursor][1] + a[cursor]);
  }

  cout << dp[n][0] << endl;
}
