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

/* add vars here */

int d;
ll g;

/* add your algorithm here */

int main() {
  cin >> d >> g;

  ll p[d], c[d];

  rep(i,d) cin >> p[i] >> c[i];
  ll ans = 100 * d + 1;

  for (int i = 0; i < (1 << d); ++i) {

    bool check[d];
    rep(i,d) check[i] = false;

    ll ts, tc;
    ts = tc = 0;
    
    for (int j = 0; j < d; ++j) {
      if (i >> j & 1) {
        check[j] = true;
        ts += p[j] * (j + 1) * 100 + c[j];
        tc += p[j];
      }
    }

    if (ts >= g) {
      ans = min(ans, tc);
      continue;
    }

    for (int j = d-1; j >= 0; --j) {
      bool flag = false;
      if (check[j]) continue;

      if (ts + ((j + 1) * 100) * p[j] + c[j] < g) {
        ts += ((j + 1) * 100) * p[j] + c[j];
        tc += p[j];
        continue;
      }

      if (ts >= g) {
        ans = min(ans, tc);
        break;
      }

      for (int k = 1; k <= p[j]; ++k) {
        ts += (j + 1) * 100;
        if (k == p[j]) ts += c[j];
        tc++;
        if (ts >= g) {
          flag = true;
          break;
        }
      }

      if (flag) {
        ans = min(ans, tc);
        break;
      }
    }
  }

  cout << ans << endl;
}
