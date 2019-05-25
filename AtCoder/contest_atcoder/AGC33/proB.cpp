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

int main() {
  int h,w,n;
  cin >> h >> w >> n;
  int sc, sr;
  cin >> sr >> sc;

  string s,t;
  cin >> s;
  cin >> t;
  

  ll tx = sc, ty = sr;
  // R , L  
  for (int i = 0; i < n; ++i) {
    rep(j, 2) {
      if (j == 0 and s[i] == 'R') {
        tx += 1;

        if (tx > w) {
          cout << "NO" << endl;
          return 0;
        }
      }


      if (j == 1 and t[i] == 'L') {
        tx -= 1;
        if (tx <= 0) tx = 1;
      }
    }
  }

  tx = sc, ty = sr;
  // L,R
  for (int i = 0; i < n; ++i) {
    rep(j, 2) {
      if (j == 0 and s[i] == 'L') {
        tx -= 1;
        if (tx <= 0) {
          cout << "NO" << endl;
          return 0;
        }
      }

      if (j == 1 and t[i] == 'R') {
        tx += 1;
        if (tx > w) tx = w;
      }
    }
  }

  tx = sc, ty = sr;
  // D,U
  for (int i = 0; i < n; ++i) {
    rep(j, 2) {
      if (j == 0 and s[i] == 'D') {
        ty -= 1;
        if (ty <= 0) {
          cout << "NO" << endl;
          return 0;
        }
      }

      if (j == 1 and t[i] == 'U') {
        ty += 1;
        if (ty > h) ty = h;
      }
    }
  }

  tx = sc, ty = sr;
  // U,D
  for (int i = 0; i < n; ++i) {
    rep(j, 2) {
      if (j == 0 and s[i] == 'U') {
        ty += 1;
        if (ty > h) {
          cout << "NO" << endl;
          return 0;
        }
      }

      if (j == 1 and t[i] == 'D') {
        ty -= 1;
        if (ty <= 0) ty = 0;
      }
    }
  }


  cout << "YES" << endl;
}
