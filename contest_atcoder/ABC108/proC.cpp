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

ll n,k;

/* add your algorithm here */

int main() {
  cin >> n >> k;
  ll c = 0;

  for (int i = 1; i <= n; ++i) {
    if (i % k == 0) {
      ++c;
    }
  }

  ll ans = 1;
  ans = c * c * c;
  if (!(k % 2)) {
    ll t = k / 2;
    ll cd = 0;

    for (int i = 1; i <= n; ++i) {
      if (i % k == t) {
        cd++;
      }
    }

    ans += cd * cd * cd;
  }

  cout << ans << endl;
}
