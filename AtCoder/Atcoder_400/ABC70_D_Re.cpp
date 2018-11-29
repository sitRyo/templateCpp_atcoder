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

typedef struct tree {
  ll to;
  ll cost;
} tree;

ll co[100010];
vector<tree> node[100010];

void dfs (ll v, ll p, ll c) {
  co[v] = c;
  for (auto itr : node[v]) {
    if (itr.to == p) continue;
    dfs(itr.to, v, c+itr.cost);
  }
}

int main() {
  ll n;
  cin >> n;

  rep(i,n-1) {
    ll a,b,c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].pb({b,c});
    node[b].pb({a,c});
  }

  ll q,k;
  cin >> q >> k;
  k--;

  rep(i,n) co[i] = 0;
  dfs(k,-1,0);

  rep(i,q) {
    ll x,y;
    cin >> x >> y;
    x--,y--;
    cout << co[x] + co[y] << endl;
  }
}
