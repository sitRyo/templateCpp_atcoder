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

vector<ll> t;
ll T,N;

/* add your algorithm here */

int main() {
  cin >> N >> T;
  ll tt;
  rep(i,N) {
    cin >> tt;
    t.pb(tt);
  }

  ll ans = 0;
  ll tmp = t[0];

  if (N == 1) {
    ans += T;
    cout << ans << endl;
    return 0;
  }

  for (int i = 1; i < N; ++i) {
    bool flag = false;
    if (t[i-1] + T < t[i]) {
      ans += t[i-1] + T - tmp;
      tmp = t[i];
      flag = true;
    }

    if (i == N-1 && flag) {
      ans += T;
    } else if (i == N-1 && !flag) {
      ans += t[i] + T - tmp;
    }
  }

  cout << ans << endl;
}
