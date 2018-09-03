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

  ll ans = 0;
  for (int i = 1; i <= n; i += 2) {
    ll c = 0;
    for (int j = 1; j <= i; ++j) {
      if (i % j == 0) {
        c++;
      }
    }

    if (c == 8) ans++;
  }

  cout << ans << endl;
}
