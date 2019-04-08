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
  ll n;
  cin >> n;
  vector<ll> a(n), sum(n+1, 0);

  rep(i, n) {
    cin >> a[i];
  }

  sorti(a);

  for (int i = 0; i < n; ++i) {
    sum[i + 1] += sum[i] + a[i];
  }

  ll ans = 0;

  for (int i = 1; i < n; ++i) {
    ll now = sum[i];
    if (sum[i] * 2 >= a[i]) {
      ans += 1;
    } else {
      ans = 0;
    }
  }

  ans += 1;

  cout << ans << endl;
}
