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
#define MAX 100
#define MOD 1000000007
#define pb push_back

typedef pair<int, int> pint;
typedef pair<pint, pint> ppint;

/* add vars here */

ll h,w;


/* add your algorithm here */

int main() {
  cin >> h >> w;
  int odd = 0;
  vector< vector<int> > tb(h, vector<int>(w,0));
  rep(i,h)rep(j,w) {
    cin >> tb[i][j];
    if (tb[i][j] & 1) ++odd;
  }

  vector<ppint> v;
  int num = 0;
  int x = 0, y = 0;

  for (int itr = 0; itr < h*w; ++itr) {
    if (tb[x][y] & 1) ++num;

    int nx = x, ny = y;
    if (x % 2 == 0) {
      if (ny == w-1) ++nx;
      else ++ny;
    }
    else {
      if (ny == 0) ++nx;
      else --ny;
    }
    if (num & 1) if (num < odd) v.pb(ppint(pint(x,y), pint(nx,ny)));
    x = nx, y = ny;
  }

  cout << v.size() << endl;
  for (auto p : v) {
    cout << p.first.first+1 << " " << p.first.second+1 << " " << p.second.first+1 << " " << p.second.second+1 << endl;
  }
}
