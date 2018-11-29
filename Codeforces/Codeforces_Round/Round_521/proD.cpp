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
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

/*
1077D Cutting out
最大 total / k　個同じ数列を切り取ることができる
k個同じ数列を作る条件 -> 要素xがk個以上存在する.

val = total / k　とすると,
val -> val-1 -> val-2 -> ... -> 1
*/

const int MAX = 200 * 1000 + 1;

int n,k;
vector<ll> s,t;
vector<ll> cnts(MAX, 0);

bool can(ll x) {
  t.clear();
  for (ll i = 1; i <= MAX; ++i) {
    ll tmp = min<ll>(cnts[i] / x, k - t.size());
    rep(j,tmp) {
      t.pb(i);
    }
  }

  return (t.size() == k) ? true : false;
}

int main() {
  cin >> n >> k;
  s = vector<ll>(n);

  rep(i,n) {
    cin >> s[i];
    cnts[s[i]]++;
  }

  if (k == 1) {
    ll mmax = -1;
    ll ans = -1;
    for (int i = 1; i <= MAX; ++i) {
      ll tmp = mmax;
      mmax = max(mmax, cnts[i]);
      if (mmax != tmp) {
        ans = i;
      }
    }

    cout << ans << endl;
    return 0;
  }

  int total = n / k;

  while (total > 0) {
    if (can(total)) {
      break;
    }
    total--;
  }

  for (auto itr : t) {
    cout << itr << " ";
  }

  END;
}
