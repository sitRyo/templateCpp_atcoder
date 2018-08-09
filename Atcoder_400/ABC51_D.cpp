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

#define INF 1000000000
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007

/* add vars here */

ll N,M;
int a[1000], b[1000], c[1000], dist[1000][1000];

/* add your algorithm here */

void wf() {
  rep(i,N) {
    rep(j,N) {
      rep(k,N) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
}

int main() {
  cin >> N >> M;

  rep(i,N) {
    rep(j,N) {
      if (i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }
  }

  rep(i,M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--,b[i]--;
    dist[a[i]][b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }

  ll ans = M;
  wf();

  rep(i,M) {
    bool shortest = false;
    for (int j = 0; j < N; ++j) if (dist[j][a[i]] + c[i] == dist[j][b[i]]) shortest = true;
    if (shortest) ans--;
  }

  cout << ans << endl;
}
