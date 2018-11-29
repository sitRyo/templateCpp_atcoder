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
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n), sum(n+1, 0);
  rep(i,n) {
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
  }

  vector<ll> num;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      ll tmp = sum[j] - sum[i-1];
      num.pb(tmp);
    }
  }

  vector<ll> pw;
  ll tt = 1;
  for (int i = 1; i <= 40; ++i) {
    pw.pb(tt);
    tt *= 2;
  }

  ll res = 0;
  for (int i = 39; i >= 0; --i) {
    ll cnt = 0, target = pw[i];
    vector<ll> tmp;
    for (auto itr : num) {
      if ((itr & target) == target) {
        cnt++;
        tmp.pb(itr);
      }
    }

    if (cnt >= k) {
      num = tmp;
      res += target;
    }
  }

  cout << res << endl;
}
