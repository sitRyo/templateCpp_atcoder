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
#include <queue>
using namespace std;

typedef long long ll;

#define INF 10e6
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

typedef pair<int, int> P; // firstは最短距離, secondは頂点の番号
typedef struct edge {int to, cost;} edge;
vector<edge> g[100002];
int d[100002];
int V;

void dijkstra(int s) {
  priority_queue<P,vector<P>,greater<P> > que;
  for (int i = 0; i <= V; ++i) d[i] = INF;
  d[s] = 0;
  que.push(P(0,s));

  while (!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;

    if (d[v] < p.first) continue;

    for (int i = 0; i < g[v].size(); ++i) {
      edge e = g[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> V;
  rep(i,V-1) {
    int a,b; scanf("%d %d", &a, &b);
    g[a].pb({b,1});
    g[b].pb({a,1});
  }
  int f_cost[V+1], s_cost[V+1];

  dijkstra(1);
  rep(i,V+1) {
    f_cost[i] = d[i];
  }

  dijkstra(V);
  rep(i,V+1) {
    s_cost[i] = d[i];
  }

  int scnt = 0, fcnt = 0;
  for (int i = 1; i <= V; ++i){
    if (f_cost[i] <= s_cost[i]) {
      fcnt++;
    } else {
      scnt++;
    }
  }
  // cout << fcnt << " " << scnt << endl;
  if (fcnt <= scnt) {
    cout << "Snuke" << endl;
  } else {
    cout << "Fennec" << endl;
  }
}
