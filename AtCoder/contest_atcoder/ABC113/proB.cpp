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
  double ans;
  int n,t,a;
  cin >> n;
  cin >> t >> a;
  ll h[n];
  rep(i,n) {
    cin >> h[i];
  }

  ans = t - h[0] * 0.006;
  ll res = 1;
  for (int i = 1; i < n; ++i) {
    double tmp = t - h[i] * 0.006;
    if (abs(ans - a) < abs(tmp - a)) {
      ;
    } else {
      ans = tmp;
      res = i + 1;
    }
  }

  cout << res << endl;
}
