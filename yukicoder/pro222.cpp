/*
 * No.220 世界のなんとか2
 */

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

ll dp[20][3][2][2]; // i桁目で,  各桁の和, 3がつく？ small or black

template <class T = ll>
T solve(string s) {
  dp[0][0][0][0] = 1;
  // debug(s);
  int len = s.size();
  rep(i, s.size()) {
    int x = s[i] - '0';
    // debug(digit);
    rep(j, 3) {
      rep(d, 10) {
        if (d < x) {
          if (d == 3) {
            dp[i + 1][(j + d) % 3][1][1] += dp[i][j][0][1] + dp[i][j][0][0] 
              + dp[i][j][1][0] + dp[i][j][1][1];
          } else {
            dp[i + 1][(j + d) % 3][0][1] += dp[i][j][0][1] + dp[i][j][0][0];
            dp[i + 1][(j + d) % 3][1][1] += dp[i][j][1][1] + dp[i][j][1][0];
          }
        } else if (d == x) {
          if (d == 3) {
            dp[i + 1][(j + d) % 3][1][1] += dp[i][j][0][1] + dp[i][j][1][1];
            dp[i + 1][(j + d) % 3][1][0] += dp[i][j][0][0] + dp[i][j][1][0];
          } else {
            dp[i + 1][(j + d) % 3][0][1] += dp[i][j][0][1];
            dp[i + 1][(j + d) % 3][1][1] += dp[i][j][1][1];
            dp[i + 1][(j + d) % 3][0][0] += dp[i][j][0][0];
            dp[i + 1][(j + d) % 3][1][0] += dp[i][j][1][0];
          }
        } else {
          // x < d
          if (d == 3) {
            dp[i + 1][(j + d) % 3][1][1] += dp[i][j][1][1] + dp[i][j][0][1];
          } else {
            dp[i + 1][(j + d) % 3][0][1] += dp[i][j][0][1];
            dp[i + 1][(j + d) % 3][1][1] += dp[i][j][1][1];
          }
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < 3; ++i) {
    if (i == 0) {
      ans += dp[len][i][0][0] + dp[len][i][0][1];
      ans += dp[len][i][1][0] + dp[len][i][1][1];
    }
      
    else 
      ans += dp[len][i][1][0] + dp[len][i][1][1];
  }

  return ans - 1;
}

int main() {
  int t;
  cin >> t;
  string s;
  s.reserve(t + 1);
  s += '1';
  for (int i = 0; i < t; ++i) {
    s += '0';
  }
  // debug(s);
  cout << solve(s) << endl;
}
