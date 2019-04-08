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
  int n;
  cin >> n;
  vector<vector<ll> > a(n,vector<ll>(n));
  vector<vector<ll> > d(n+1,vector<ll>(n+1, INF));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      d[i][j] = a[i][j];
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (k == i or k == j or i == j or d[i][k] == INF or d[k][j] == INF) continue;
        if (a[i][k] + d[k][j] == a[i][j]) d[i][j] = INF;
        else if (d[i][k] + d[k][j] < a[i][j]) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  ll ans = 0;
  for (auto itr : d) {
    for (auto sub : itr) {
      if (sub != INF) ans += sub;
    }
  }

  cout << ans / 2 << endl;
}
