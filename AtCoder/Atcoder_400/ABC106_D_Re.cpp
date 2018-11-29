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
  int train[n+1][n+1];

  rep(i,n+1)rep(j,n+1) train[i][j] = 0;

  rep(i,m) {
    int l,r; cin >> l >> r;
    train[l][r]++;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      train[i][j] += train[i-1][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      train[i][j] += train[i][j-1];
    }
  }

  rep(i,qq) {
    int p,q; cin >> p >> q;
    int cnt = 0;
    cnt = train[q][q] + train[p-1][p-1] - train[p-1][q] - train[q][p-1];
    cout << cnt << endl;
  }
}
