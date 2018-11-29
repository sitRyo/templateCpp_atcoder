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

#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

const ll INF = 1LL << 50;

int main() {
  int N,M;
  cin >> N >> M;

  const int NMAX = 1000;
  const int MMAX = 2000;
  int a[MMAX], b[MMAX];
  ll c[MMAX];

  rep(i,M) {
    cin >> a[i] >> b[i] >> c[i];
    c[i] = -c[i];
  }

  ll dist[NMAX];

  rep(i,N) dist[i] = INF;

  dist[0] = 0;

  for (int loop = 0; loop < N-1; ++loop) {
    for (int i = 0; i < M; ++i){
      if (dist[a[i] - 1] == INF) continue;

      if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
        dist[b[i] - 1] = dist[a[i] - 1] + c[i];
      }
    }
  }

  ll ans = dist[N-1];

  rep(i,N) printf("dist[%d]: %lld ", i, dist[i]);
  printf("\n");

  bool negative[NMAX];

  rep(i,N) negative[i] = false;

  for (int loop = 0; loop < N-1; ++loop) {
    for (int i = 0; i < M; ++i) {
      if (dist[a[i] - 1] == INF) continue;

      if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
        dist[b[i] - 1] = dist[a[i] - 1] + c[i];
        negative[b[i] - 1] = true;
      }

      if (negative[a[i] - 1] == true) {
        negative[b[i] - 1] = true;
      }
    }
  }

  rep(i,N) {
    if (negative[i]) cout << i << " " << endl;
  }

  if (negative[N - 1]) {
    cout << "inf" << endl;
  } else {
    cout << -ans << endl;
  }
}
