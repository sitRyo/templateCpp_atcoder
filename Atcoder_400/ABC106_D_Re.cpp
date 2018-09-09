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
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll n,m,qq;

/* add your algorithm here */

int main() {
  cin >> n >> m >> qq;

  // 2次元累積和
  ll table[n+1][n+1];

  rep(i,n+1) {
    rep(j,n+1) {
      table[i][j] = 0;
    }
  }

  rep(i,m) {
    ll l,r;
    cin >> l >> r;
    table[l][r]++;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      table[i][j] += table[i][j-1];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      table[i][j] += table[i-1][j];
    }
  }

  ll ans = 0;
  rep(i,qq) {
    ll p,q;
    cin >> p >> q;
    ans = table[q][q] - table[p-1][q] - table[q][p-1] + table[p-1][p-1];
    cout << ans << endl;
  }

}
