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
#include <map>
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
  Ti <= Ai -> Ai-1 <= Ti <= Ai となるAiを見つける
  Ti > Amax -> min{(Amax - Ai) + Bi} + (Ti - Amax)
*/

int main() {
  int n,m;
  cin >> n;

  map<ll,ll> mp;
  vector<ll> a(n);
  rep(i,n) {
    ll x,y; scanf("%lld %lld", &x, &y);
    a[i] = x;
    mp[x] = y;
  }

  cin >> m;
  vector<ll> t(m);
  rep(i,m) scanf("%lld", &t[i]);

  sorti(a);
  // 最大の通話時間のプランを超えるときに最小のものを求める
  ll mmin = mp[a.back()];
  for (auto itr : a) {
    // コスト
    ll b = mp[itr];
    ll between = a.back() - itr;
    ll tmp = between + b;
    mmin = min(tmp, mmin);
  }

  // m個を2分探索
  for (auto itr : t) {
    int l = 0, r = n;
    while (l - r > 0) {
      int mid = (l + r) / 2;
      int target = mp[a[mid]];
      cout << target << endl;
      if (target > itr) {
        r = mid;
      } else {
        l = mid;
      }
    }


  }


}
