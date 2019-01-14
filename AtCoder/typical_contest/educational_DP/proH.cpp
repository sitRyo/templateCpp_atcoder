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

#define INF 10e18 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int h,w;
  cin >> h >> w;
  string s[h+1];
  vector<vector<ll> > dp(h+1,vector<ll>(w+1,0));

  rep(i,h) {
    cin >> s[i];
  }
  

  dp[0][0] = 1;
  rep(i,h) {
    rep(j,w) {
      if (i != h-1 and s[i+1][j] != '#') {
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= MOD;
      }
      if (j != w-1 and s[i][j+1] != '#') {
        dp[i][j+1] += dp[i][j];
        dp[i][j+1] %= MOD;
      }
    }
  }

  cout << dp[h-1][w-1] << endl;
}
