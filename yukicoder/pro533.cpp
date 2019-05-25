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
#include <map>
#include <unordered_map>
#include <set>
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
  cin >> n;
  vector<vector<ll>> dp(n + 10, vector<ll>(3, 0));
  dp[0][0] = 1; dp[1][0] = 1;
  for (int i = 0; i < n; ++i) {
    rep(j, 3) {
      rep(k, 3) {
        if (j == k) continue;
        int step = k + 1;
        dp[i + step][k] += dp[i][j] % MOD;
      }
    }
  }

  // rep(i, n + 1) cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;

  ll ans = 0;
  rep(i, 3) ans += dp[n][i] % MOD;
  cout << ans % MOD << endl;
}
