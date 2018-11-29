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
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n;
  cin >> n;
  vector<ll> a(n,0);

  rep(i,n) {
    ll tmp; scanf("%lld", &tmp);
    a[i] = tmp;
  }

  ll res = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      if (a[i] >= 2) {
        res += a[i] / 2;
        a[i] = a[i] % 2;
      }
    } else {
      if (a[i-1] > 0) {
        if (a[i] >= a[i-1]) {
          res += a[i-1];
          a[i] -= a[i-1];
          a[i-1] = 0;
          if (a[i] >= 2) {
            res += a[i] / 2;
            a[i] %= 2;
          }
        } else {
          res += a[i];
          a[i-1] -= a[i];
          a[i] = 0;
        }
      } else {
        if (a[i] >= 2) {
          res += a[i] / 2;
          a[i] %= 2;
        }
      }
    }
  }

  cout << res << endl;
}
