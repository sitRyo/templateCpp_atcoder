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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

void solve(ll const n, ll const lim) {
  ll dp[20][200];
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 200; ++j) {
      dp[i][j] = 11234567890123456;
    }
  }
  
  rep(i, 10) dp[0][i] = i;
  
  ll t = 10;
  for (int i = 1; i < 20; ++i) {
    for (int d = 0; d < 10; ++d) {
      rep(j, 190) {
        dp[i][j + d] = min(dp[i][j + d], dp[i - 1][j] + (t * d));
      }
      if (dp[i][lim] == n) dp[i][lim] = 11234567890123456;
    }
    t *= 10;
  }

  cout << dp[18][lim] << endl;
}

int main() {
  ll n,cpy,lim = 0;
  cin >> n;
  cpy = n;
  while (cpy > 0) {
    lim += (cpy % 10);
    cpy /= 10;
  }
  solve(n, lim);
}
