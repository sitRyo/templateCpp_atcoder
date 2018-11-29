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
  int h,w;
  cin >> h >> w;

  ll cost[10][10];
  int wall[h][w];

  rep(i,10)rep(j,10) cin >> cost[i][j];
  rep(i,h)rep(j,w) cin >> wall[i][j];

  rep(k,10)rep(i,10)rep(j,10) cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

  ll ans = 0;
  rep(i,h)rep(j,w) {
    if (wall[i][j] == -1 or wall[i][j] == 1) continue;
    ans += cost[wall[i][j]][1];
  }

  cout << ans << endl;
}
