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

int main() {
  ll n, h;
  cin >> n >> h;

  vector<ll> a(n), b(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
  }

  sortd(b);
  sorti(a);

  ll mmax = a.back();
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll bt = b[i];
    if (bt >= mmax) {
      ans += 1;
      h -= bt;
    } else {
      break;
    }
  }
  
  if (h <= 0) {
    cout << ans << endl;
  } else {
    ans += h / mmax;
    if (h % mmax > 0) {
      ans += 1;
    }
    cout << ans << endl;
  }
}
