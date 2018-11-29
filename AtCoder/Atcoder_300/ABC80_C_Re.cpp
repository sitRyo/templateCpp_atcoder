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

ll n;

/* add your algorithm here */

int main() {
  cin >> n;

  int f[n+1][2];
  rep(i,n)rep(j,2) scanf("%d", &f[i][j]);

  ll p[n+1][11];
  rep(i,n)rep(j,11) scanf("%lld", &p[i][j]);

  ll res = - 10e7;

  for (int b = 1; b < (1 << 10); ++b) {
    ll cc = 0;
    for (int i = 0; i < 10; ++i) {
      ll c = 0;
      for (int j = 0; j < 10; ++j) if ((b >> j & 1) && f[i][j]) ++c;
      cc += p[i][c];
    }
    if (res < cc) res = cc;
  }
  cout << res << endl;
}
