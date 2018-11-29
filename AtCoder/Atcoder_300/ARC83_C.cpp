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
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  double ans = 0;
  vector<int> water, suger;
  int tp = lcm(a,b);
  int sp = lcm(c,d);
  for (int i = 1; i*100*a <= f; ++i) {
    water.pb(100*a*i);
  }

  for (int i = 1; i*100*b <= f; ++i) {
    if (!(i * b % tp)) {
      continue;
    }
    water.pb(100*i*b);
  }

  for (int i = 1; i*c <= f; ++i) {
    suger.pb(i*c);
  }

  for (int i = 1; i*d <= f; ++i) {
    if (!((i * d) % sp)) {
      continue;
    }
    suger.pb(i*d);
  }

  sorti(suger);
  sorti(water);

  pair<int, int> res;
  for (auto itr : water) {
    double suger_max = (itr / 100) * e, total = itr, s = 0;
    for (auto sug : suger) {
      if (s + sug <= suger_max) {
        if (total + sug <= f) {
          total += sug;
          s += sug;
          double tmp = (s/total) * 100.0;
          if (tmp > ans) {
            res = make_pair(total, s);
            ans = tmp;
          }
        }
      }
    }
    double tmp = ((double)(s/total) * 100);
    if (tmp > ans) {
      res = make_pair(total, s);
      ans = tmp;
    }
  }

  cout << res.first << " " << res.second << endl;
}
