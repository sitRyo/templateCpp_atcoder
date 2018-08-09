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

#define inf 10000000
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

const int nmax = 40, abmax = 10;
int a[nmax], b[nmax], c[nmax];
int dp[nmax + 1][nmax * abmax + 1][nmax * abmax + 1];

/* add your algorithm here */

int main() {
  int n, ma, mb;
  cin >> n >> ma >> mb;

  rep(i,n) {
    cin >> a[i] >> b[i] >> c[i];
  }

  rep(i,n+1) {
    rep(ca, nmax*abmax+1) {
      rep(cb, nmax*abmax+1) {
        dp[i][ca][cb] = inf;
      }
    }
  }

  dp[0][0][0] = 0;

  rep(i,n) {
    rep(ca, nmax*abmax+1) {
      rep(cb, nmax*abmax+1) {
        if (dp[i][ca][cb] == inf) continue;
        dp[i+1][ca][cb] = min(dp[i+1][ca][cb], dp[i][ca][cb]);
        dp[i+1][ca + a[i]][cb + b[i]] = min(dp[i+1][ca + a[i]][cb + b[i]], dp[i][ca][cb] + c[i]);
      }
    }
  }

  int ans = inf;

  for (int ca = 1; ca <= nmax * abmax; ++ca) {
    for (int cb = 1; cb <= nmax * abmax; ++cb) {
      if (ca * mb == cb * ma) ans = min(ans, dp[n][ca][cb]);
    }
  }

  if (ans == inf) ans = -1;
  cout << ans << endl;
}
