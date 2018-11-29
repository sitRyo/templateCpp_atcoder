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

const int limit = 100010;

typedef struct edge {
  int to;
  ll cost;
} edge;

vector<edge> tree[limit];
ll depth[limit];

void dfs (int v, int p, ll d) {
  depth[v] = d;
  for (auto &e : tree[v]) {
    if (e.to == p) continue;
    dfs(e.to, v, d + e.cost);
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    tree[a].pb({b,c});
    tree[b].pb({a,c});
  }

  int q,k;
  cin >> q >> k;
  k--;

  dfs(k, -1, 0);
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << depth[x] + depth[y] << endl;
  }
}
