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
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int H, W, X;
  string S[1000];
  int d1[1000][1000], d2[1000][1000];
  const int dx[] = {1, -1, 0, 0};
  const int dy[] = {0, 0, 1, -1};

  cin >> H >> W >> X;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      d1[i][j] = -1;
      d2[i][j] = -1;
    }
  }

  pair<int, int> s;
  queue<pair<int, int>> que;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == 'S') s = {i,j};
      if (S[i][j] == '@') {
        que.push({i,j});
        d1[i][j] = 0;
      }
    }
  }

  while (que.size()) {
    auto p = que.front(); que.pop();
    int x = p.first, y = p.second;
    for (int k = 0; k < 4; ++k) {
      int x2 = x + dx[k], y2 = y + dy[k];
      if (S[x2][y2] == '#' or d1[x2][y2] >= 0) continue;
      d1[x2][y2] = d1[x][y] + 1;
      que.push({x2,y2});
    }
  }

  que.push(s);
  d2[s.first][s.second] = 0;
  while(que.size()) {
    auto p = que.front(); que.pop();
    int x = p.first, y = p.second;
    for (int k = 0; k < 4; ++k) {
      int x2 = x + dx[k], y2 = y + dy[k];
      if (S[x2][y2] == '#' || d2[x2][y2] >= 0 || (d1[x2][y2] >= 0 && d1[x2][y2] <= X)) continue;
      if (S[x2][y2] == 'G') {
        cout << d2[x][y] + 1 << endl;
        return 0;
      }

      d2[x2][y2] = d2[x][y] + 1;
      que.push({x2,y2});
    }
    cout << -1 << endl;
    return 0;
  }
}
