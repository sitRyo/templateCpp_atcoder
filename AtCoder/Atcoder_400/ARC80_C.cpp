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

ll factorize_two(ll x) {
  ll res = 0;
  while (x % 2 == 0) {
    res++;
    x /= 2;
  }
  return res;
}

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  map<int, int> mp;
  for (auto itr : a) {
    ll tmp = factorize_two(itr);
    if (tmp >= 2) mp[2] += 1;
    else if (tmp == 1) mp[1] += 1;
    else if (tmp == 0) mp[0] += 1;
  }

  ll s = floor(n / 2);
  if (mp[2] >= s) {
    cout << "Yes" << endl;
  } else {
    ll t = n - 2 * mp[2];
    if (mp[1] >= t) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
