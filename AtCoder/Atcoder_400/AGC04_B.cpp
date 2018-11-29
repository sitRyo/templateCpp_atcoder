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

/*
考察
スライムを捕まえる操作は一番短い時間で済むものにしたい
xがスライムを捕まえる時間に比べて十分に短かったら
1
2
1 2
2 3
1 2 3
捕まえる時間が一番短いスライムを捕獲 -> 魔法
を繰り返せば良い

xが大きい場合
小さいスライムを捕獲して，変色

基本指針
捕獲時間がｘ以下だったらまとめて変色
*/

int main() {
  ll n,x; scanf("%lld %lld", &n, &x);
  vector<pair<ll,ll>> a(n);
  // a.first -> 捕獲時間，a.second -> スライムの番号
  rep(i,n) {
    ll t; cin >> t;
    a[i] = make_pair(t,i);
  }

  sorti(a);

  int total = 0;
  ll ans = 0;
  vector<bool> check(n,false);
  vector<int> h,e;

  while (total != n) {
    ll tsum = 0;
    for (int i = 0; i < n; ++i) {
      if (check[a[i].second] == false) {
        tsum += a[i].first;
        if (tsum > x && h.size() != 0) {
          tsum -= a[i].first;
        }
        h.pb(i);
      }
    }

    ans += tsum;
    e.clear();
    rep(i,n) check[i] = false;
    for (auto itr : h) {
      if (itr == n-1) {
        check[0] = true;
        e.pb(0);
      } else {
        check[itr + 1] = true;
        e.pb(itr+1);
      }
    }
    h.clear();
    total = e.size();
    if (total != h.size()) {
      ans += x;
    }
  }

  cout << ans << endl;
}
