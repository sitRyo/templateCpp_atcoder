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

int main() {
  int N, W;
  cin >> N >> W;

  vector<ll> w(N), v(N);

  rep(i, N) {
    cin >> w[i] >> v[i];
  }

  vector< vector<ll> > dp(N+1, vector<ll>(W+1, 0));

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= W; ++j) {
      if (j - w[i - 1] >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << dp[N][W] << endl;
}
