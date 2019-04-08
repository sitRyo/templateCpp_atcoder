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

void add (ll& a, ll b) {
  a = (a + b) % MOD;
}

ll dp[101][4][4][4]; // 0123 : TAGC

bool ng(int a, int b, int c) {
  return (a == 1 and b == 2 and c == 3);
}

int main() {
  int N;
  cin >> N;

  dp[0][0][0][0] = 1;

  rep(i, N) rep(a, 4) rep(b, 4) rep(c, 4) rep(d, 4) {
    // 3文字がNG 左から a, b, c, d(AGC, GAC, ACG)
    if (ng(b, c, d) or ng(c, b, d) or ng(b, d, c)) {
      continue;
    }

    if (ng(a, c, d) or ng(a, b, d)) continue;

    add(dp[i+1][b][c][d], dp[i][a][b][c]);
  }

  ll ans = 0;
  rep(a, 4)rep(b, 4)rep(c, 4) add(ans, dp[N][a][b][c]);
  cout << ans << endl;
}
