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

ll n,s;

ll f(ll b, ll n) {
  ll res = 0;
  while (n > 0) {
    res += n % b;
    n /= b;
  }
  return res;
}

int main() {
  cin >> n >> s;

  if (n == s) {
    cout << n + 1 << endl;
    return 0;
  }

  for (ll b = 2; b * b <= n; ++b) {
    if (f(b,n) == s) {
      cout << b << endl;
      return 0;
    }
  }

  ll ans = INF;
  for (ll p = 1; p * p <= n; ++p) {
    ll b = (n - s) / p + 1;
    if (b < 2) continue;
    if (f(b,n) == s) ans = min(ans,b);
  }

  cout << (ans == INF ? -1 : ans) << endl;
}
