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

/* add vars here */

int x,y,n,m;

/* add your algorithm here */

int main() {
  cin >> n >> m >> x >> y;
  vector<ll> xx(n,0);
  vector<ll> yy(m,0);
  rep(i,n) cin >> xx[i];
  rep(i,m) cin >> yy[i];
  sort(xx.begin(), xx.end());
  sort(yy.begin(), yy.end());

  for (int i = x+1; i <= y; ++i) {
    if (i > xx.back() and i <= yy.front()) {
      cout << "No War" << endl;
      return 0;
    }
  }

  cout << "War" << endl;
}
