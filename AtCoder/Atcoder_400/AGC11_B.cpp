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
  vector<ll> a(n), sum(n+1);
  sum[0] = 0;
  ll mmax = -1;
  rep(i,n) {
    cin >> a[i];
  }
  sorti(a);
  ll res = 0, tmp = a.back();
  a.pb(tmp);
  rep(i,n) {
    sum[i+1] = a[i] + sum[i];
    if (a[i+1] > sum[i+1] * 2) {
      res = 0;
    } else {
      res++;
    }
  }

  if (res == 0) res = 1;

  cout << res << endl;
}
