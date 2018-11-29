#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <map>
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


// 最大公約数を求める(ユークリッドの互除法).
ll gcd (ll x, ll y) {
  if (y > x) swap(x,y);
  if (y == 0) return x;
  return gcd(x%y,y);
}

// 最小公倍数を求める(lcm(a,b) = a*b / gcd(a,b)). overflowに気をつけよう
ll lcm (ll x, ll y) {
  ll t = gcd(x,y);
  return (x / t) * y;
}


int main() {
  int n,m;
  cin >> n >> m;
  string s,t;
  cin >> s;
  cin >> t;

  if (s[0] != t[0]) {
    cout << -1 << endl;
    return 0;
  }
  ll res = lcm(n,m);

  int s1 = n / res, s2 = m/res;
  int mmax = min(s1,s2);

  map<int, char> mp;

  for (int i = 0; i < n; ++i) {
    mp[i*(res/n) + 1] = s[i];
  }

  for (int i = 0; i < m; ++i) {
    if (mp[i*(res/m) + 1]) {
      if (mp[i*(res/m) + 1] != t[i]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << res << endl;
}
