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

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

struct edge { long long to, cost;};
typedef pair<long long, long long> P_dij;

/* params
 * @s -> start, n -> 要素数, G -> グラフ, d -> 結果(参照渡し)
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

/* END END END */
int main() {
  int n;
  cin >> n;
  vector<vector<edge>> G(n+1);
  
  int a,b;
  rep(i, n-1) {
    cin >> a >> b;
    --a, --b;
    G[a].push_back({b, 1});
    G[b].push_back({a, 1});
  }

  vector<ll> d1, d2;
  dijkstra(0, n, G, d1);
  dijkstra(n-1, n, G, d2);

  int cntf = 0, cnts = 0;
  for (int i = 0; i < n; ++i) {
    if (d1[i] < d2[i]) cntf += 1;
    else if (d1[i] == d2[i]) cntf += 1;
    else cnts += 1;
  }

  if (cnts > cntf or cnts == cntf) {
    cout << "Snuke" << endl;
  } else {
    cout << "Fennec" << endl;
  }
}
