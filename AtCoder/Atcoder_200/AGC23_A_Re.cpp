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
  int n; cin >> n;
  vector<ll> a(n), sum(n+1);
  sum[0] = 0;
  rep(i,n) {
    cin >> a[i];
    sum[i+1] = a[i] + sum[i];
  }

  map<ll,int> mp;
  for (int i = 1; i <= n; ++i) {
    mp[sum[i]] += 1;
  }
  ll ans = 0;
  mp[0] += 1;
  for (auto itr : mp) {
    if (itr.second > 1) {
      ll t = itr.second;
      ans += (t-1) * t / 2;
    }
  }
  cout << ans << endl;
}
