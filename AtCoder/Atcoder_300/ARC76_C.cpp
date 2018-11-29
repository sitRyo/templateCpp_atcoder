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


/* add your algorithm here */

int main() {
  ll n,m;
  cin >> n >> m;
  ll ans = 0;

  if (abs(m-n) >= 2) {
    cout << ans << endl;
  } else if (m == n) {
    ll tmp1 = 1, tmp2 = 1;
    for (int i = m; i > 0; --i) {
      tmp1 *= i;
      tmp1 %= MOD;
    }

    tmp2 = tmp1;
    tmp1 *= 2;
    tmp1 %= MOD;
    tmp2 %= MOD;
    tmp1 *= tmp2;
    tmp1 %= MOD;
    cout << tmp1 << endl;
  } else if (abs(m-n) == 1) {
    ll tmp1 = 1, tmp2 = 1;
    for (int i = m; i > 0; --i) {
      tmp1 *= i;
      tmp1 %= MOD;
    }
    for (int i = n; i > 0; --i) {
      tmp2 *= i;
      tmp2 %= MOD;
    }
    ans = (tmp1 * tmp2) % MOD;
    cout << ans << endl;
  }
}
