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
  int t;
  cin >> t;
 
  vector<int> a(t+1000);
  rep(i,t) {
    cin >> a[i];
  }
  ll dp[600][1000];
  for (int i = 0; i < 600; ++i) for (int j = 0; j < 1000; ++j) dp[i][j] = 0;
  ll ans = 0;
  dp[0][0] = 1;
  
  rep(i, 599) rep(j, 600) rep(k, a.at(i) + 1) {
    if (j % 2 == 0) {
      dp[i + 1][k + j / 2] = (dp[i + 1][k + j / 2] + dp[i][j]) % MOD;
    }
  }
  for (int i = 1; i < 600; ++i) {
    ans += dp[i][1];
    ans %= MOD;
  }
  cout << ans << endl;
}
