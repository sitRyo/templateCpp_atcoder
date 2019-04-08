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

int d[2001][2001], u[2001][2001], r[2001][2001], l[2001][2001];

int main() {
  int n,m;
  cin >> n >> m;

  vector<string> s(n);
  rep(i,n) cin >> s[i];

  
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    // left
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '.') {
        l[i][j] = cnt;
        cnt += 1;
      } else {
        cnt = 0;
        l[i][j] = cnt;
      }
    }
    cnt = 0;
    // right
    for (int j = m - 1; j >= 0; --j) {
      if (s[i][j] == '.') {
        r[i][j] = cnt;
        cnt += 1;
      } else {
        cnt = 0;
        r[i][j] = cnt;
      }
    }
  }
/*
  cout << "left" << endl;
  rep(s, n) {
      END;
      rep(t, m) {
        cout << l[s][t] << " ";
    }
  }

  END;

  cout << "right" << endl;

  rep(s, n) {
    END;
    rep(t, m) {
      cout << r[s][t] << " ";
    }
  } 

  END;
*/
  for (int i = 0; i < m; ++i) {
    int cnt = 0;
    // up
    for (int j = 0; j < n; ++j) {
      if (s[j][i] == '.') {
        u[j][i] = cnt;
        cnt += 1;
      } else {
        cnt = 0;
        u[j][i] = cnt;
      }
    }
    cnt = 0;
    // down
    for (int j = n - 1; j >= 0; --j) {
      if (s[j][i] == '.') {
        d[j][i] = cnt;
        cnt += 1;
      } else {
        cnt = 0;
        d[j][i] = cnt;
      }
    }
  }
  /*
  cout << "up" << endl;

  rep(s, n) {
    END;
    rep(t, m) {
      cout << u[s][t] << " ";
    }
  }

  END;

  cout << "down" << endl;

  rep(s, n) {
    END;
    rep(t, m) {
      cout << d[s][t] << " ";
    }
  }
  END;
  */
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '.') {
        ans += (l[i][j] + r[i][j]) * (u[i][j] + d[i][j]);
      }
    }
  }

  cout << ans << endl;
}
