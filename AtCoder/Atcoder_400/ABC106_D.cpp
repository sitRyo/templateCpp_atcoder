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
#define END cout << endl


int main() {
  ll n,m,q;
  cin >> n >> m >> q;

  ll cum[n+2][n+2];
  rep(i,n+2)rep(j,n+2) {
    cum[i][j] = 0;
  }

  rep(i,m) {
    ll l,r; cin >> l >> r;
    cum[l][r] += 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cum[i][j] += cum[i][j-1];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cum[i][j] += cum[i-1][j];
    }
  }

  rep(i,q) {
    ll q,r;
    cin >> q >> r;

    cout << cum[r][r] + cum[q-1][q-1] - cum[q-1][r] - cum[r][q-1] << endl;
  }
}
