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

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int dx[4] = {1, 0 , -1, 0}, dy[4] = {0, 1, 0, -1};
typedef pair<int, int> pi;

int main() {
  int h,w;
  cin >> h >> w;

  char field[h][w];
  int d[h][w], bc = 0;
  rep(i,h)rep(j,w) {
    cin >> field[i][j];
    if (field[i][j] == '#') bc++;
    d[i][j] = 1000000;
  }

  queue<pi> que;
  que.push(make_pair(0,0));
  d[0][0] = 0;

  while (que.size() > 0) {
    pi p = que.front(); que.pop();
    if (p.first == h-1 and p.second == w-1) {
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 <= nx and nx < h and ny < w and ny >= 0 and field[nx][ny] != '#' and d[nx][ny] == 1000000) {
        que.push(make_pair(nx,ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }

  if (d[h-1][w-1] == 1000000) {cout << -1 << endl; return 0;}
  int ans = h*w - bc - 1 - d[h-1][w-1];

  cout << ans << endl;
}
