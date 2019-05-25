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

ll dp[12][12][2];

ll solve(string s) {
  ll size = s.size();
  dp[0][0][0] = 1;

  rep(i, size) rep(j, i + 1) {
    int now = s[i] - '0';
    
    rep(d, 10) {
      if (d < now) {
        if (d == 1) {
          dp[i + 1][j + 1][1] += dp[i][j][0] + dp[i][j][1];
        } else {
          dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
        }
      } else if (d == now) {
        if (d == 1) {
          dp[i + 1][j + 1][1] += dp[i][j][1];
          dp[i + 1][j + 1][0] += dp[i][j][0];
        } else {
          dp[i + 1][j][1] += dp[i][j][1];
          dp[i + 1][j][0] += dp[i][j][0];
        }
      } else {
        // d > now
        if (d == 1) {
          dp[i + 1][j + 1][1] += dp[i][j][1];
        } else {
          dp[i + 1][j][1] += dp[i][j][1];
        }
      }
    }
  }

  ll ans = 0;
  rep (i, 12) {
    ans += (dp[size][i][0] + dp[size][i][1]) * i;
  }

  return ans;
}

int main() {
  string n;
  cin >> n;
  
  cout << solve(n) << endl;
}
