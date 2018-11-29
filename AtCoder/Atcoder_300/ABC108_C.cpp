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
  ll ans = 0;

  ll cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % k == 0) ++cnt;
  }
  ans = cnt * cnt * cnt;
  cnt = 0;
  if (k % 2 == 0) {
    for (int i = 1; i <= n; ++i) {
      if (i % k == (k/2)) {
        cnt++;
      }
    }
  }
  ans += cnt * cnt * cnt;

  cout << ans << endl;
}
