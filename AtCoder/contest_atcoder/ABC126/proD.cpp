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

struct edge {
  ll to;
  ll cost;
};
typedef pair<long long, long long> P_dij;	

 /* params	
 * @s -> start, n -> 要素数, G -> グラフ, d -> 結果(参照渡し)	
 * グラフの要素を0 ~ n - 1として見る	
*/	
void dijkstra(const long long s, const long long n,	
  vector< vector<edge> > const &G, vector<long long> & d){	
  d.resize(n);	
  for(int i=0; i<n; i++) d[i] = INF; 	
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
}	



int main() {
  int n;
  cin >> n;
  ll u,v,w;
  vector< vector<edge> > G(n);
  rep(i,n-1) {
    cin >> u >> v >> w;
    u--, v--;
    G[u].push_back({v,w});
    G[v].push_back({u,w});
  }

  vector<ll> d, d2;
  vector<bool> ans(n);
  
  dijkstra(0, n, G, d);
  
  ans[0] = 1;
  ll cnt = 0, tm = 0;
  for (int i = 1; i < n; ++i) {
    if (d[i] % 2 == 0) {
      ans[i] = 1;
    } else {
      cnt += 1;
      tm = i;
    }
  }
  
  /*
  if (cnt == 1) {
    dijkstra(0, n, G, d2);
    for (int i = 0; i < n; ++i) {
      if (i == tm) continue;
      if (d2[i] % 2 == 0) {
        ans[i] = 0;
        break;
      }
    }
  }*/
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
  }
}
