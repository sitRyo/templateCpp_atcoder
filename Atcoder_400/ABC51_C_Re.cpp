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

#define INF 1000000
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll n,m;
ll a[1001],b[1001],c[1001];
ll dist[1001][1001];

/* add your algorithm here */

int main() {
  cin >> n >> m;
  rep(i,m) cin >> a[i] >> b[i] >> c[i];


  for (int i = 1; i < n+1; ++i) {
    for (int j = 1; j < n+1; ++j) {
      if (i == j) {
        dist[i][j] = 0;
      } else {
        dist[i][j] = INF;
      }
    }
  }

  rep(i,m){
    dist[a[i]][b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }
  for (int i = 1; i < n+1; ++i) {
    for (int j = 1; j < n+1; ++j) {
      for (int k = 1; k < n+1; ++k) {
        dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
      }
    }
  }

  // 全ての辺に対して
  ll ans = m;
  for (int i = 0; i < m; ++i) {
    bool flag = true;
    for (int s = 1; s < n+1; ++s) {
      for (int t = 1; t < n+1; ++t) {
        if (s == t) continue;
        if (dist[s][a[i]] + dist[t][b[i]] == dist[s][t]) flag = false;
      }
    }

    if (flag) ans--;
  }

  cout << ans << endl;
}
