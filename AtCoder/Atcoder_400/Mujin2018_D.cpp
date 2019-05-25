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

int rev(int x) {
  int t = 0, ten = 1;
  vector<int> v;
  while (x > 0) { v.push_back(x % 10); x /= 10; }
  for (int i = 0; i < v.size() - 1; ++i) {
    ten *= 10;
  }
  for (int i = 0; i < v.size(); ++i) {
    t += v.at(i) * ten;
    ten /= 10;
  }

  return t;
}

vector< vector<int> > G;

int main() {
  const int MAX = 1000;
  int N, M; cin >> N >> M;
  int V = MAX * MAX;
  G.assign(V, vector<int>());

  vector<int> deg(V, 0);
  for (int x = 1; x < MAX; ++x) {
    for (int y = 1; y < MAX; ++y) {
      int nx = x, ny = y;
      if (x < y) nx = rev(x);
      else ny = rev(y);
      if (nx < ny) ny -= nx;
      else nx -= ny;

      int from = x * MAX + y;
      int to = nx * MAX + ny;
      G[to].push_back(from);
      deg[from] += 1;
    }
  }

  queue<int> que;
    vector<int> seen(V, 0);
    for (int v = 0; v < V; ++v) if (deg[v] == 0) que.push(v);
    while (!que.empty()) {
        auto v = que.front(); que.pop();
        seen[v] = true;
        for (auto nv : G[v]) {
            if (seen[nv]) continue;
            --deg[nv];
            if (deg[nv] == 0) que.push(nv);
        }
    }

    // 答え
    int res = 0;
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= M; ++y) {
            int id = x * MAX + y;
            if (!seen[id]) ++res;
        }
    }
    cout << res << endl;
}