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

typedef pair<int,int> pi;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int d[1001][1001];

int main() {
  pi a,b,c;
  cin >> a.first >> a.second;
  cin >> b.first >> b.second;
  cin >> c.first >> c.second;

  queue<pi> que;
  rep(i,1001)rep(j,1001) d[i][j] = INF;
  que.push(a);
  d[a.first][a.second] = 0;
  bool flag1 = false, flag2 = false;

  while (que.size()) {
    pi p = que.front(); que.pop();
    if (p.first == b.first and p.second == b.second) flag1 = true;
    if (p.first == c.first and p.second == c.second) flag2 = true;

    if (flag1 and flag2) {
      break;
    }


    for (int i = 0; i < 4; ++i) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 <= nx and nx <= 1000 and 0 <= ny and ny <= 1000 and d[nx][ny] == INF) {
        que.push(pi(nx,ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  int res = 0;
  int ad = 0, bd = d[b.first][b.second], cd = d[c.first][c.second];
  if (a.first == b.first and a.first == c.first) {
    if (a.second > b.second and c.second > a.second) {
      res = bd + cd;
    } else if (a.second > c.second and a.second < b.second) {
      res = bd + cd;
    } else {
      res = max(bd,cd);
    }
  } else if (a.second == b.second and b.second == c.second) {
    if (a.first > b.first and a.first < c.first) {
      res = bd + cd;
    } else if (a.first > c.first and a.first < b.second) {
      res = bd + cd;
    } else {
      res = max(bd,cd);
    }
  } else if ()

  cout << res << endl;

}
