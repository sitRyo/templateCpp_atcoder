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
#define END cout << endl
#define MOD 1000000007
#define pb push_back

int main() {
  ll n,x;
  cin >> n >> x;
  vector<ll> gab(n,0);
  rep(i,n) {
    cin >> gab[i];
  }

  ll ans = 0;
  vector<bool> isg(n,0);

  for (int i = n-1; i >= 0; --i) {
    if (isg[i]) continue;
    cout << i << endl;
    ans += gab[i] + x; isg[i] = true;
    ll have = 1, now = gab[i];
    for (int j = i-1; j > 0; --j) {
      ll tmp = (have + 2) * (have + 2);
      ll d1 = gab[j] + gab[j] * 4 + 2 * x;
      ll d2 = gab[j] * tmp + x;
      if (d2 < d1) {
        ans += d2 + (now - gab[j]);
        have++;
        now = gab[j];
        isg[j] = true;
      }
    }

    ans += x;
  }

  cout << ans << endl;
}
