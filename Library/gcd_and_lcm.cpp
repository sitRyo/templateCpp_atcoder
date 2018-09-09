#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

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

// test
int main() {
  ll x,y;
  cin >> x >> y;
  cout << lcm(x,y) << endl;
}
