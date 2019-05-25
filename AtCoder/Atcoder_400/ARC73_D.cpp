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

ll N, W;
ll w[128], v[128];
ll dp[128][512];

int main() {
  cin >> N >> W;
  rep(i, N) cin >> w[i] >> v[i];

  ll sum = 0;
  rep(i, N) {
    ll ww = w[i] - w[0];

    for (int j = i; j >= 0; j--) {
      for (int k = sum; k >= 0; k--) {
        dp[j + 1][k + ww] = max(dp[j+1][k+ww],dp[j][k]+v[i]);
      }
    }
    sum += ww;
  }

  ll ans = 0;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=sum;j++){
      if(w[0]*i+j>W) continue;
        ans = max(ans,dp[i][j]);
    }
  }
  cout << ans << endl;
}
