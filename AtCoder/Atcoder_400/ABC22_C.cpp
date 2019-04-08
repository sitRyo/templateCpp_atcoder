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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

#define N 301

ll cost[N][N];
int n,m;

void floyd_warshall() {
  for (ll k = 2; k < n+1; ++k) {
    for (ll i = 2; i < n+1; ++i) {
      for (ll j = 2; j < n+1; ++j) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  rep(i,n+1) {
    rep(j,n+1) {
      cost[i][j] = INF;
    }
  }

  rep(i,n+1) cost[i][i] = 0;
  rep(i,m) {
    int u,v,l;
    cin >> u >> v >> l;
    cost[u][v] = l;
    cost[v][u] = l;
  }

  floyd_warshall();
  ll mmin = INF;
  rep(i,n) rep(j,n) {
    if (cost[1][j] != INF and cost[i][1] != INF and i != j and i != 1 and j != 1) 
      mmin = min(mmin, cost[1][j] + cost[i][1] + cost[i][j]);
  }

  if (mmin > m) mmin = -1;
  cout << mmin << endl;
}
