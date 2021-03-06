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

#define INF 10e18 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

struct edge { ll to, cost; };

vector<vector<ll> > G;
vector<ll> memo;

ll dp(ll i) {
  if (memo[i] != -1) return memo[i];
  ll res = 0;
  for (auto v : G[i]) res = max(res, dp(v) + 1);
  return memo[i] = res;
}

int main() {
  int n,m;
  cin >> n >> m;
  vector<ll> x(m), y(m);
  rep(i,m) {
    cin >> x[i] >> y[i];
  }
  
  G.resize(n+1);
  rep(i,m) G[x[i]].pb(y[i]);

  memo.resize(n+1, -1);
  ll ans = 0;
  rep_r(i,n+1,1) ans = max(dp(i), ans);

  cout << ans << endl;
}
