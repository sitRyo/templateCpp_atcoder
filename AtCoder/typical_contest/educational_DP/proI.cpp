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
  int n; cin >> n;
  vector<double> p(n+1);
  vector<vector<double> > dp(n+1, vector<double>(n+1,0));
  rep(i,n) cin >> p[i+1];
  dp[0][0] = 1.0;

  for (int i = 1; i <= n; ++i) {
    double pi = p[i];
    rep(j,n) {
      dp[i][j] += dp[i-1][j] * (1.0 - pi);
      dp[i][j+1] += dp[i-1][j] * pi;
    }
  }

  double ans = 0;
  int h = (n+1) / 2;
  for (int i = h; i <= n; ++i) ans += dp[n][i];
  printf("%.9f\n", ans);
}
