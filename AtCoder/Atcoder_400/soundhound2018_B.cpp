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
  vector<ll> b(n);

  ll sum = 0;
  rep(i, n) {
    cin >> b[i];
    sum += b[i];
  }

  vector<vector<ll>> dp(n+2, vector<ll>(2, -INF));
  dp[n][0] = 0;
  for (int i = n - 1; i >= 0; --i) {
    chmax(dp[i][0], dp[i+1][0] + b[i]);
    if (i + k <= n) chmax(dp[i][1], dp[i+k][0]);
    chmax(dp[i][1], dp[i+1][1]);
    chmax(dp[i][0], dp[i+1][1] + b[i]);
  }

  cout << max(dp[0][0], dp[0][1]) << endl;
}
