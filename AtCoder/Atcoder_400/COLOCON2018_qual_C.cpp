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
#include <map>
#include <set>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define debug(x) cout << (x) << endl;
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

// 最大公約数を求める(ユークリッドの互除法).
ll gcd (ll x, ll y) {
  if (y > x) swap(x,y);
  if (y == 0) return x;
  return gcd(x%y,y);
}

ll A,B;

int main() {
  cin >> A >> B;
  vector<ll> v[2];
  for (ll x = A; x <= B; ++x) v[x % 2].pb(x);

  int n = v[1].size(), m = v[0].size();
  int ans = 0;
  for (int msk = 0; msk < 1 << n; ++msk) {
    vector<ll> x;
    for (int i = 0; i < n; ++i) if (msk & (1 << i)) x.pb(v[1][i]);
    bool ok = true;
    int nm = x.size();
    for (int i = 0; i < nm; ++i) {
      for (int j = i+1; i < nm; ++j) {
        if (gcd(x[i], x[j]) != 1) ok = false;
      }
    }
    if (ok) ans++;
    else continue;

    for (int mm = 0; mm < m; ++mm) {
      bool ok = true;
      rep(i,nm) if (gcd(x[i], v[0][mm]) != 1) ok = false;
      if (ok) ans++;
    }
    cout << 3 << endl;
  }

  cout << ans << endl;
}
