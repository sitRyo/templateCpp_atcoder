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
#define MAX 100
#define MOD 1000000007

/* add vars here */

int cost[1000][1000];
int d[1000];
bool used[1000];
int V;

/* add your algorithm here */

void dijkstra_me(int s) {
  fill(d, d + V, INF);
  fill(used, used + V, false);
  d[s] = 0;

  while(true) {
    int v = -1;
    // まだ使われていない頂点のうち距離が最小のものを探す
    for (int u = 0; u < V; ++u) {
      if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }

    if (v == -1) break;

    used[v] = true;
    for (int u = 0; u < V; ++u) {
      d[u] = min(d[u], d[v] + cost[u][v]);
    }
  }
}

int main() {

}
