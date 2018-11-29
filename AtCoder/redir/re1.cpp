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

#define INF 10e8
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

typedef pair<ll,ll> P;

int main() {
  int n,m;
  cin >> n >> m;

  int a[1000], b[1000], c[1000], dist[100][100];

  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--, b[i]--;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }
  }

  for (int i = 0; i < m; ++i) {
    dist[a[i]][b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int ans = m;
  rep(i,m) {
    bool shortest = false;
    rep(j,n) if(dist[j][a[i]] + c[i] == dist[j][b[i]]) shortest = true;
    if (shortest) ans--;
  }

  cout << ans << endl;
}
