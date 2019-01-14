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
#define debug(x) cout << (x) << endl;
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n,m;
  cin >> n >> m;

  char f[n+2][m+2];
  int up[n+2][m+2], left[n+2][m+2], right[n+2][m+2], down[n+2][m+2];

  rep(i,n+2)rep(j,m+2) {
    f[i][j] = '#';
    up[i][j] = -1;
    left[i][j] = -1;
    right[i][j] = -1;
    down[i][j] = -1;
  }

  rep(i,n)rep(j,m) scanf("%c", &f[i+1][j+1]);

  for (int i = 0; i <= n+2; ++i) {
    for (int j = 0; j <= m+2; ++j) {
      if (f[i][j] == '.') {
        up[i][j] += up[i-1][j] + 1;
        left[i][j] += left[i][j-1] + 1;
      }
    }
  }

  for (int i = n+1; i >= 0; --i) {
    for (int j = m+1; j >= 0; --j) {
      if (f[i][j] == '.') {
        down[i][j] = down[i+1][j] + 1;
        right[i][j] = right[i][j+1] + 1;
      }
    }
  }

  cout << "up" << endl;
  for (int i = 0; i < n+2; ++i) {
    for (int j = 0; j < m+2; ++j) {
      cout << up[i][j] << " ";
    }
    END;
  }

  cout << "down" << endl;
  for (int i = 0; i < n+2; --i) {
    for (int j = 0; j < m+2; --j) {
      cout << down[i][j] << " ";
    }
    END;
  }

  cout << "left" << endl;
  for (int i = 0; i < n+2; ++i) {
    for (int j = 0; j < m+2; ++j) {
      cout << left[i][j] << " ";
    }
    END;
  }

  cout << "right" << endl;
  for (int i = 0; i < n+2; ++i) {
    for (int j = 0; j < m+2; ++j) {
      cout << right[i][j] << " ";
    }
    END;
  }
}
