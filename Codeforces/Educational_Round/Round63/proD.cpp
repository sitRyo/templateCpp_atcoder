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
#include <set>
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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i,n) {
    scanf("%lld", &a[i]);
  }

  ll dp[n + 1][3][3];
  debug(1);
  for (int i = 0; i <= n; ++i) 
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k) 
        dp[i][j][k] = INF;
  
  dp[0][0][0] = 0;

  for (int i = 0; i < n + 1; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (k < 2)
          dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
        if (j < 2)
          dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
        if (i < n)
          dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + (j == 1 ? a[i] : 0) * MOD(k == 1 ? x : 1));
      }
    }
  }

  printf("%lld\n", dp[n][2][2]);
  
}
