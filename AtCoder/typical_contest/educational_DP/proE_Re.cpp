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
  ll N, W, mmax = 0;
  cin >> N >> W;

  vector<ll> w(N), v(N);
  rep(i, N) {
    cin >> w[i] >> v[i];
    mmax += v[i];
  }
  // cout << mmax << endl;

  vector< vector<ll> > dp(N+1, vector<ll>(mmax+1010, INF));

  for (int i = 1; i <= N; ++i) {
    ll tw = w[i - 1], tv = v[i - 1];
    for (int j = 1; j <= mmax; ++j) {
      if (j == tv) {
        dp[i][j] = min(dp[i - 1][j], tw);
      } else if (j - tv >= 0 and dp[i - 1][j - tv] != INF) {
        cout << i << " " << j << " " << dp[i - 1][j - tv]  << endl;
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - tv] + tw);
      }
    }
  }
  /*
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= mmax; ++j) {
      cout << dp[i][j] << " ";
    }
    END;
  }*/

  ll ans = 0;
  for (int i = 1; i <= mmax; ++i) {
    if (dp[N][i] <= W) ans = i;
  }

  cout << ans << endl;
}
