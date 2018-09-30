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
#define rep_r(m,i,n) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back

typedef pair<ll,ll> point;

int main() {
  int k,n;
  cin >> n >> k;

  vector<int> x(n), y(n);
  vector<int> xary, yary;

  rep(i,n) {
    cin >> x[i] >> y[i];
    xary.pb(x[i]), yary.pb(y[i]);
  }

  sort(begin(xary), end(xary));
  sort(begin(yary), end(yary));

  ll ans = 1LL * (xary[n-1] - xary[0]) * (yary[n-1] - yary[0]);

  rep(xi,n)rep_r(xi+1,xj,n)rep(yi,n)rep_r(yi+1,yj,n) {
    int num = 0;
    ll lx = xary[xi], rx = xary[xj];
    ll by = yary[yi], uy = yary[yj];

    rep(i,n) if (lx <= x[i] and x[i] <= rx and by <= y[i] and y[i] <= uy) num++;

    if (num >= k) ans = min(ans, 1LL * (rx - lx) * (uy - by));
  }

  cout << ans << endl;
}
