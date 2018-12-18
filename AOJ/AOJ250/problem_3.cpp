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

#define INF 10e8
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
  int n;
  while (cin >> n && n) {
    vector<vector<int> > stage(n, vector<int>(n+1, 0));
    rep(i,n)rep(j,n+1) cin >> stage[i][j];

    vector<int> dp(1 << n, INF);
    dp[0] = 0;
    // 1 ~ n
    for (int bit = 0; bit < (1 << n); ++bit) {
      rep(i,n) {
        if ( (bit & (1 << i)) != 0) continue;
        int cost = stage[i][0];
        rep(j,n) {
          if ( (bit & (1 << j)) == 0) continue;
          cost = min(stage[i][j+1], cost);
        }
        int now = (bit | (1 << i));
        dp[now] = min(dp[now], dp[bit] + cost);
      }
    }
    cout << dp[(1 << n) - 1] << endl;
  }
}
