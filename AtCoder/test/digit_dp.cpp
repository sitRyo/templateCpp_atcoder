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
#include <array>
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

// 10000までの自然数でxより小さいものはいくつあるか？
ll solve(ll x) {
  string s = to_string(x);
  int size = s.size();
  ll dp[10][2] = {}; // i桁目まで見て, xを超えないことが確定している 0, 未確定 1
  dp[0][0] = 1;
  rep(i, 6) rep(j, 2) {
    int t = j ? s[i] + 1 : 10;
    rep(d, t) {
      dp[i+1][j || d < t] += dp[i][j];
    }
  }

  return dp[6][1] + dp[6][0];
}

int main() {
  ll n;
  cin >> n;

  cout << solve(n) << endl;
}
