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

int main() {
  ll n; cin >> n;
  vector<ll> even, odd;
  vector<ll> total(n,0);
  ll sume = 0, sumo = 0;

  rep(i,n) {
    ll a; cin >> a;
    total[i] = a;
    if (i % 2 == 0) {
      even.pb(a);
      sume += a;
    } else {
      odd.pb(a);
      sumo += a;
    }
  }

  sorti(even); sorti(odd);

  bool flag = true;
  for (int i = 1; i < n; ++i) {
    if (total[i] != total[i-1]) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << even.size() << endl;
    return 0;
  }

  ll aveE, aveO;
  aveE = sume / even.size();
  aveO = sumo / odd.size();

  ll ans1 = 0 , ans2 = 0;
  for (auto itr : even) {
    ans1 += abs(itr - aveE);
  }
  for (auto itr : odd) {
    ans2 += abs(itr - aveO);
  }
  ll res = 0;
  if (aveE == aveO) {
    for (int i = -1; i <= 1; i += 2) {
      ll tmp1 = 0, tmp2 = 0;
      for (auto itr : even) {
        tmp1 += abs(itr - aveE + i);
      }
      for (auto itr : odd) {
        tmp2 += abs(itr - aveO + i);
      }
      res = min(tmp1 + ans2, tmp2 + ans1);
    }
  }
  if (res == 0) res = ans1 + ans2;
  cout << res << endl;

}
