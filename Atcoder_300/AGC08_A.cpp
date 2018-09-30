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

ll x, y;

/* add your algorithm here */

int main() {
  cin >> x >> y;

  ll res = 0;
  if (x == 0 && y < 0) {
    res = abs(x-y) + 1;
    cout << res << endl;
    return 0;
  }
  if (x > 0 && y == 0) {
    res = x + 1;
    cout << res << endl;
    return 0;
  }
  if (x > y && x < 0) {
    ll t1 = -x;
    ll t2 = abs(t1 - (-y));
    res += t2 + 2;
  } else if (x > y && y > 0) {
    res = x + y;
  } else {
    ll t1,t2;
    t1 = abs(y - x), t2 = abs((-x) - y);
    if (t1 <= t2) {
      res = t1;
    } else {
      res = t2 + 1;
    }
  }

  cout << res << endl;
}
