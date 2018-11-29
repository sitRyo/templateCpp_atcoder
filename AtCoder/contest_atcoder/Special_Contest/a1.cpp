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

ll c,d;
ll ans = 0;

/* add your algorithm here */

int main() {
  cin >> c >> d;

  ll mmin = 140;
  ll mmax = 170;

  while (true) {
    ll tmax = mmax;
    ll tmin = mmin;

    if (tmin > d) {
      break;
    }

    if (c >= tmax) {
      mmin *= 2;
      mmax *= 2;
      continue;
    }

    if (tmin < c) {
      tmin = c;
    }

    if (tmax > d) {
      tmax = d;
    }
    ans += tmax - tmin;
    mmin *= 2;
    mmax *= 2;
  }

  cout << ans << endl;
}
