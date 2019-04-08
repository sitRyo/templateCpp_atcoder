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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), sum(n+1, 0);

  rep(i, n) {
    cin >> a[i];
    sum[i + 1] += (sum[i] + a[i]) % m;
  }
  map<ll, ll> mp;
  for (int i = 1; i <= n; ++i) {
    mp[sum[i]] += 1;
  }
  ll ans = 0;
  for (auto itr : mp) {
    if (itr.first == 0) {
      itr.second += 1;
    }

    ans += (itr.second * (itr.second - 1)) / 2;
  }

  cout << ans << endl;
}
