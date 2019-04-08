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

#define INF 10e8
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n,m;

  cin >> n >> m;
  vector<vector<int> > cost(n+1, vector<int>(n+1, 10000));
  
  for (int i = 0; i < m; ++i) {
    int a,b;
    cin >> a >> b;
    
    cost[a][b] = 1;
    cost[b][a] = 1;
  }
  
  for (int i = 0; i <= n; ++i) {
    cost[i][i] = 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
      }
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (cost[i][j] == 2) ans += 1;
    }
    cout << ans << endl;
  }
}
