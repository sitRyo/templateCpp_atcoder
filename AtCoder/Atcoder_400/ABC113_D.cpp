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

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int h,w,k;
  cin >> h >> w >> k;
  vector<vector<int> > dp(h+1, vector<int>(w,0)); dp[0][0] = 1;

  rep(i,h) {
    rep(j,w) {
      cout << j << endl;
      for (int k = 0; k < 1 << (w - 1); ++k) {
        bool ok = true;
        for (int l = 0; l < w-2; ++l) {
          if (((k >> l) & 1) && ((k >> (l + 1)) & 1)) {
            ok = false;
          }
        }

        if (ok) {
          if (j >= 1 && ((k >> (j - 1)) & 1)) {
            dp[i+1][j-1] += dp[i][j];
            dp[i+1][j-1] %= MOD;
          } else if (j <= w - 2 && ((k >> j) & 1)) {
            dp[i+1][j+1] += dp[i][j];
            dp[i+1][j+1] %= MOD;
          } else {
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
          }
        }
      }
    }
  }

  cout << dp[h][k-1] << endl;
}