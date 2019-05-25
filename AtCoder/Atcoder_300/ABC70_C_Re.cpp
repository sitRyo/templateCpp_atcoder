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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}
// 最大公約数を求める(ユークリッドの互除法).
long long gcd (long long x, long long y) {
  if (y > x) swap(x,y);
  if (y == 0) return x;
  return gcd(x%y,y);
}


// 最小公倍数を求める(lcm(a,b) = a*b / gcd(a,b)). overflowに気をつけよう
ll lcm (long long  x, long long y) {
  ll t = gcd(x,y);
  return (x / t) * y;
}
int main() {
  int n;
  cin >> n;
  vector<ll> t(n);
  rep(i, n) cin >> t[i];

  ll p = t[0];
  rep(i, n) {
    p = lcm(p, t[i]);
  }

  cout << p << endl;
}
