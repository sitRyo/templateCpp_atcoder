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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

struct edge { long long to, cost;};
typedef pair<long long, long long> P_dij;

vector<long long> dijkstra(const long long s, const long long n, vector< vector<edge> > const &G){
vector<long long> d = {};
  d.resize(n);
  for(int i=0; i<n; i++){
    d[i] = INF;
  }
  priority_queue<P_dij, vector<P_dij>, greater<P_dij>> que;
  d[s] = 0;
  que.push(P_dij(0, s));
  while (!que.empty()) {
    P_dij p = que.top();
    que.pop();
    long long v = p.second;
    if(d[v] < p.first)continue;
    for(int i=0;i<G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P_dij(d[e.to], e.to));
      }
    }
  }
  return d;
}

int main() {
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  ll MAX = 10e14, mmax = -1;
  vector<vector<edge> > yen(n + 1), snuuk(n + 1);
  rep(i, m) {
    ll u, v, a, b;
    cin >> u >> v >> a >> b;
    yen[u].push_back({v, a});
    yen[v].push_back({u, a});

    snuuk[u].push_back({v, b});
    snuuk[v].push_back({u, b});
  }
  vector<ll> d1, d2, ans;
  d1 = dijkstra(s, n + 1, yen);
  d2 = dijkstra(t, n + 1, snuuk);
  for (int i = n; i > 0; --i) {
    ll t = MAX - (d1[i] + d2[i]);
    mmax = max(t, mmax);
    ans.push_back(mmax);
  }

  for (int i = n - 1; i >= 0; --i) {
    cout << ans[i] << endl;
  }
}
