#include <iostream>
#include <map>
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

int main() {
  ll n,k;
  cin >> n >> k;

  map<ll,ll> divs;
  rep(i,n) {
    ll tmp; cin >> tmp;
    ll di = gcd(tmp, k);
    divs[di] += 1;
  }
  ll res = 0;
  for (auto i : divs) {
    for (auto j : divs) {
      if ((i.first * j.first) % k == 0 && i.first <= j.first) {
        if (i.first == j.first) {
          res += i.second * (i.second-1) / 2;
        } else {
          res += i.second * j.second;
        }
      }
    }
  }
  cout << res << endl;
}
