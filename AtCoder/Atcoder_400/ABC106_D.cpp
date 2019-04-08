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

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector< vector<int> > data(n+1, vector<int>(n+1, 0));

  rep(i, m) {
    int x, y;
    cin >> x >> y;
    data[x][y] += 1;
  }

  vector< vector<int> > sum2(n+1, vector<int>(n+1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sum2[i][j] += sum2[i][j - 1] + data[i][j];
    }
  }

  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= n; ++i) {
      sum2[i][j] += sum2[i - 1][j];
    }
  }
/*
  rep(i, n+1) {
    END;
    rep(j, n+1) {
      cout << sum2[i][j] << " ";
    }
  }
  END;
*/
  rep(i, q) {
    int x, y;
    cin >> x >> y;
    cout << sum2[y][y] + sum2[x-1][x-1] - sum2[x-1][y] - sum2[y][x-1] << endl;
  }
}
