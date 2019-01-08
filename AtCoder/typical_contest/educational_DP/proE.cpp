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

ll dp[101][101000];

int main() {
  ll n,wei;
  scanf("%lld %lld", &n, &wei);
  vector<ll> w(n), v(n);
  rep(i,n) scanf("%lld %lld", &w[i], &v[i]);

  for (int i = 0; i <= 100010; ++i) {
    dp[0][i] = INF;
  }
  dp[0][0] = 0;

  // 品物
  for (int i = 0; i < n; ++i) {
    // 価値 
    for (int j = 0; j <= 100000; ++j) {
      if (v[i] < j) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
    }
  }

  ll ans;
  for (int i = 0; i <= 100000; ++i) {
    
    if (dp[n][i] <= wei) ans = i;
  }

  cout << ans << endl;
}
