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
  int n; cin >> n;

  ll res = 1;

  for (int i = 2; i <= n; ++i) {
    ll qmax = n / i;
    if (qmax == 1) {
      ll mm = 1;
      rep(j,10) {
        mm *= i % MOD;
      }
      cout << mm << endl;

      res += (mm * 2) % MOD;
      
      continue;
    }
    ll psum = 1, qsum = 1;
    rep(j,10) {
      psum *= i % MOD;
      qsum *= qmax % MOD;
    }

    if (psum == 0) psum = MOD;
    if (qsum == 0) qsum = MOD;
    if (psum < 0) psum = MOD - 1;
    if (qsum < 0) qsum = MOD - 1;

    ll tmp = (psum * qsum) % MOD;
    tmp = (tmp * 2) % MOD;
    tmp -= (psum + qsum - 2) % MOD;
    res += tmp;
  }

  cout << res << endl;
}
