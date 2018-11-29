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
#define END cout << endl
#define MOD 1000000007
#define pb push_back

int main() {
  int n,m,r;
  cin >> n >> m >> r;

  vector<int> city(r,0);
  rep(i,r) {
    cin >> city[i];
    city[i]--;
  }

  bool d[n+1][n+1];
  ll cost[n+1][n+1];

  rep(i,n)rep(j,n){
    d[i][j] = false;
    if (i == j) {
      cost[i][j] = 0;
    } else {
      cost[i][j] = INF;
    }
  }

  rep(i,m) {
    int x,y,c;
    cin >> x >> y >> c;
    x--,y--;

    cost[x][y] = cost[y][x] = c;
    d[x][y] = d[y][x] = true;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }

  ll ans = 0;
  sort(city.begin(), city.end());

  rep(i,city.size() - 1) {
    ans += cost[city[i]][city[i+1]];
  }
  while (next_permutation(city.begin(), city.end())) {
    ll tmp = 0;
    rep(i,city.size() - 1) {
      tmp += cost[city[i]][city[i+1]];
    }
    ans = min(ans,tmp);
  }

  cout << ans << endl;
}
