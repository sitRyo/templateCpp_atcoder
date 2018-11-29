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
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n), sum(n+1, 0);
  rep(i,n) {
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
  }

  vector<ll> num;
  vector<pair<ll,ll>> two;
  ll pw = 1;
  while(pw <= 10e12+1) {
    two.pb(make_pair(pw,0));
    pw *= 2;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      ll tmp = sum[j] - sum[i-1];
      num.pb(tmp);
    }
  }

  sorti(num);

  vector<ll> ans;
  ll cnt = 0, now = num.size() - 1;
  ll res = 0;

  for (int i = two.size() - 1; i > 0; --i) {
    ll tar1 = two[i].first, tar2 = two[i-1].first;
    while (now >= 0) {
      if (num[now] >= tar2 and num[now] <= tar1) {
        res = tar2;
        ans.pb(num[now]);
        cnt++;
        now--;
      } else {
        break;
      }
    }
    if (cnt >= k) break;
  }

  // res は最小
  vector<ll> count[50];
  for (auto itr : ans) {
    ll p = 0, t = itr;
    while (itr > 0) {
      if (itr % 2 == 1) {
        two[p].second += 1;
        count[p].pb(t);
      }
      itr /= 2;
      p++;
    }
  }
  for (int i = 0; i < 50; ++i) {
    sorti(count[i]);
  }
  vector<ll> b;
  for (int i = two.size() - 1; i >= 0; --i) {
    ll tm = two[i].second, su = two[i].first;
    if (tm >= k) {
      if (b.size() == 0) {
        for (auto itr : count[i]) {
          b.pb(itr);
        }
        sorti(b);
      } else {
        ll cc = 0;
        for (auto itr : count[i]) {
          auto ir = lower_bound(b.begin(), b.end(), itr);
          if (ir == b.end()) continue;
          if (*ir == itr) {
            cc++;
          }
        }
        if (cc >= k) {
          res += su;
        }
      }
    }
  }

  cout << res << endl;
}
