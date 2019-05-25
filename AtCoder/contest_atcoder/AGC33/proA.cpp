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

using pi = pair<int,int>;

int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

int main() {
  int h,w;
  cin >> h >> w;
  ll d[h][w];
  queue<pi> que;
  
  string s[h];
  rep(i, h) cin >> s[i];

  rep(i, h) rep(j, w) {
    d[i][j] = INF;
    if (s[i][j] == '#') {
      que.push(make_pair(i,j));
      d[i][j] = 0;
    }
  }

  ll cnt = 0;
  while (!que.empty()) {
    pi p = que.front();
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = dx[i] + p.second, ny = dy[i] + p.first;
      if (nx >= 0 and ny >= 0 and nx < w and ny < h and d[ny][nx] == INF and d[p.first][p.second] + 1 < d[ny][nx]) {
        if (ny == 3 and nx == 5) {
          
        }
        d[ny][nx] = d[p.first][p.second] + 1;
        que.push(make_pair(ny, nx));
      }
    }
    cnt += 1;
  }
  
  ll mmax = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      // cout << d[i][j] << " ";
      mmax = max(mmax, d[i][j]);
    }
    // END;
  }

  cout << mmax << endl;
}
