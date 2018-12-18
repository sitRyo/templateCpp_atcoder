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

ll comb(ll n, ll r) {
  if (n == r) return 1;
  ll q = 1, o = 1, sub = n - r, t = 1;
  for (int p = 1; p <= n; ++p) {
    q *= p;
  }
  o = 6;
  for (int p = 1; p <= sub; ++p) {
    t *= p;
  }
  ll tmp = o * t;
  ll res = q / tmp;
  return res;
}

int main() {
  ll n; cin >> n;
  ll t = n, digit = 0;
  vector<ll> top;
  while (t > 0) {
    top.pb(t % 10);
    t /= 10;
    digit++;
  }

  ll bac = top.back();

  if (digit < 3) {
    cout << 0 << endl;
    return 0;
  }
  ll res = 0;

  ll t1, t2 = 1;

  for (int i = 3; i <= digit-1; ++i) {
    t1 = comb(i,3);

    t1 *= 6;

    for (int j = 1; j <= i - 4; ++j) {
      t2 *= 3;
    }

    res += t1 * t2;
    cout << t2 << endl;

    t2 = 1;
  }

  t1 = 0, t2 = 1;

  if (bac < 3) {
    res += 0;
  } else {
    for (int i = 3; i <= bac - 1; ++i) {
      ll tt = digit - 1;
      if (i == 3 || i == 5 || i == 7) {
        t1 = comb(tt, 2);
        t1 *= 2;
        for (int j = 1; j <= i - 4; ++j) {
          t2 *= 3;
        }
        res += t1 * t2;
      }
    }

    if (bac == 3 || bac == 5 || bac == 7) {
      ll ten = pow(10, digit-1);

      for (ll i = bac * ten; i <= n; ++i) {
        ll tmp = i;
        bool flag = true, a = false,b = false,c = false;
        while (tmp > 0) {
          ll ttt = tmp % 10;
          if (ttt == 3) a = true;
          if (ttt == 5) b = true;
          if (ttt == 7) c = true;
          if (ttt != 3 && ttt != 5 && ttt != 7) {
            break;
            flag = false;
          }
          tmp /= 10;
        }
        if (flag and a and b and c) {
          res++;
        }
      }
    }
  }
  cout << res << endl;
}
