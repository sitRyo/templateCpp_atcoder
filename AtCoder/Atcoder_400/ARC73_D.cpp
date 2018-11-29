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

// dp[i][j] => i個使用して重さの総和がj+w0iとなるときの価値の最大値

int main() {
  ll N,W;
  scanf("%lld %lld", &N, &W);

  ll w[N], v[N];
  rep(i,N) {
    scanf("%lld %lld", &w[i], &v[i]);
  }
  ll base = 4 * N;
  ll dp[N+2][base + 5];

  ll sum = 0;
  dp[0][0] = 0;
  rep(i,N) {
    ll ww = w[i] - w[0];
    for (int j = i; j >= 0; --j) {
      for (int k = sum; k >= 0; k--) {
        dp[j+1][k+ww] = max(dp[j+1][k+ww], dp[j][k] + v[i]);
      }
    }
    sum += ww;
  }
  cout << sum << endl;
  ll res = 0;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= sum; ++j) {
      if (w[0] * i + j > W) continue;
      cout << dp[i][j] << endl;
      res = max(res, dp[i][j]);
    }
  }

  printf("%lld\n", res);
}
