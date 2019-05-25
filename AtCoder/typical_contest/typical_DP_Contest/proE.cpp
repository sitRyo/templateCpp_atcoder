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

// i桁目でmod d の数全部
ll dp[100010][101][2];

ll solve(string s, ll d) {
  dp[0][0][0] = 1;
  ll x = s.size();
  rep(i, x) rep(j, d) {

    
    
    rep(digit, 10) {
      if (digit < s[i] - '0') {
        dp[i + 1][(j + digit) % d][1] += (dp[i][j][0] + dp[i][j][1]) % MOD;
        dp[i + 1][(j + digit) % d][1] %= MOD;
      } else if (digit == s[i] - '0') {
        dp[i + 1][(j + digit) % d][0] += dp[i][j][0];
        dp[i + 1][(j + digit) % d][1] += dp[i][j][1];
        dp[i + 1][(j + digit) % d][0] %= MOD;
        dp[i + 1][(j + digit) % d][1] %= MOD;
      } else {
        dp[i + 1][(j + digit) % d][1] += dp[i][j][1];
        dp[i + 1][(j + digit) % d][1] %= MOD;
      }
    }
  }

  return (dp[x][0][0] + dp[x][0][1] - 1 + MOD) % MOD;
}

int main() {
  string s;
  ll d;

  cin >> d >> s;
  
  cout << solve(s, d) << endl;
}
