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

#define INF 10e7
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main() {
  int h,w; scanf("%d %d", &h,&w);

  char s[h][w];
  int bl = 0;
  rep(i,h)rep(j,w) {
    cin >> s[i][j];
    if (s[i][j] == '#') bl++;
  }

  queue<pair<int, int>> que;
  pair<int,int> initp = make_pair(0,0);
  que.push(initp);

  int d[h][w];
  rep(i,h)rep(j,w) d[i][j] = INF;
  d[0][0] = 0;

  while(que.size()) {
    pair<int, int> tmp = que.front(); que.pop();
    if (tmp.first == h-1 and tmp.second == w-1) break;

    for (int i = 0; i < 4; ++i) {
      int nx = tmp.first + dx[i], ny = tmp.second + dy[i];

      if (nx >= 0 and nx < h and ny >= 0 and ny < w and d[nx][ny] == INF and s[nx][ny] != '#') {
        que.push(make_pair(nx,ny));
        d[nx][ny] = d[tmp.first][tmp.second] + 1;
      }
    }
  }
  if (d[h-1][w-1] == INF) {
    cout << -1 << endl;
    return 0;
  }
  cout << h * w - bl - 1 - d[h-1][w-1] << endl;
}
