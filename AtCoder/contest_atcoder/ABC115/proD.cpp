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
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

ll res = 0;
vector<ll> L(50+1), P(50+1);

// true: left, false: right
void dfs (ll now, ll sub, bool flag) {
  if (flag == false) sub--;
  if (sub == 0) return;
  if (sub+1 == L[now]) {
    res += L[now];
  }
  if (now == 1) {
    if (sub > 0 and sub < 5) {
      res += sub;
    }
    return;
  }
  if (now == 0) {
    res += 0;
    return;
  }

  ll half = L[now] / 2;
  if (half == sub) {
    res += P[now-1];
    return;
  } else if (now > half){
    res += P[now-1] + 1;
    dfs(now - 1, sub - half+1, true);
  } else {
    dfs(now-1, sub+1, false);
  }
}

int main() {
  ll n,x; cin >> n >> x;
  L[0] = 1;
  P[0] = 1;
  x -= 1;
  for (int i = 1; i <= n; ++i) {
    L[i] = 3 + L[i-1] * 2;
    P[i] = 1 + P[i-1] * 2;
  }

  if (x+1 == L[n]) {
    cout << P[n] << endl;
    return 0;
  }

  for (int i = 0; i <= n; ++i) {
    if (L[i] <= x+1) continue;
    ll half = L[i] / 2;

    if (x == half) {
      return 0;
    } else if (x > half) {
      res += P[i-1] + 1;
      dfs(i-1, x - half+1, true);
    } else {
      dfs(i-1, x+1, false);
    }
  }

  cout << res << endl;
}
