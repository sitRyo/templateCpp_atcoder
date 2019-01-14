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

/* ダイクストラ法, vector gにedgeを入れます */
typedef pair<int, int> P; // firstは最短距離, secondは頂点の番号
typedef struct edge {int to, cost;} edge;
vector<edge> g[100002];
long long d[100002];
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

}
