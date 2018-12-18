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

int main() {
  ll n; cin >> n;
  vector<ll> a(n), tw;
  map<ll, ll> mp;
  map<ll, ll> count;
  rep(i,n) {
    cin >> a[i];
    mp[a[i]] += 1;
  }

  ll total = 1;
  while (total <= 2 * 10e14) {
    total *= 2;
    tw.pb(total);
  }

  // vector<int> vp[1000000001];

  ll res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < tw.size(); ++j) {
      ll tmp = tw[j] - a[i];
      if (tmp <= 0) continue;
      if (mp[tmp] > 0) {
        count[a[i]] += 1;
        count[tmp] += 1;
        mp[a[i]]--;
        mp[tmp]--;
        res += 2;
      } 
    }
  }
  cout << res << endl;
  cout << count.size() << endl;
  ll ans = ceil((double)count.size() / res);
  cout << ans << endl;
}
