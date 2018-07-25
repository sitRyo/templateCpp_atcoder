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
#define MAX 50

int N, A;
int x[50];

ll dp[51][51][3010];

int main() {
  cin >> N >> A;
  rep(i,N) cin >> x[i];

  dp[0][0][0] = 1;
  rep(i,N) rep(j,N) rep(k,2500) if (dp[i][j][k]) {
    dp[i+1][j][k] += dp[i][j][k];
    dp[i+1][j+1][k+x[i]] += dp[i][j][k];
  }

  ll ans=0;
  for (int i = 1; i < N+1; ++i) ans += dp[N][i][i*A];
  cout << ans << endl;
}
