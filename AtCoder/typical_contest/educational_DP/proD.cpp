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

ll dp[101][100010];

int main() {
  ll n,wei; 
  cin >> n >> wei;
  vector<ll> w(n), v(n);

  rep(i,n) {
    scanf("%lld %lld", &w[i], &v[i]);
  }

  // 品物
  for (int i = 0; i < n; ++i) {
    // 重さ
    for (int j = 0; j <= wei; ++j) {
      if (j < w[i]) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
    }
  }

  cout << dp[n][wei] << endl;
}