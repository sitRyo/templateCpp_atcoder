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
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  ll tt = 0;
  ll mmax = -1;
  rep(i,n) {
    cin >> a[i];
    mmax = max(mmax, a[i]);
    if (k == 0) {
      ll m = a[i] ^ 0;
      tt += m;
    }
  }
  mmax = max(mmax,k);
  if (k == 0) {
    cout << tt << endl;
    return 0;
  }

  map<ll,ll> mp;
  for (auto itr : a) {
    ll sum = 1;
    while (sum <= mmax) {
      int b = sum & itr;
      // cout << b << endl;
      if (b == 0) mp[sum] += 1;
      sum *= 2;
    }
  }

  int kmax = 1;
  ll sum = 1;
  bool flag = false;
  while (sum <= k) {
    kmax *= 2;
    sum *= 2;
    if (k == sum - 1) flag = true;
  }

  if (kmax == sum) kmax /= 2;

  ll ans = 0;
  map<ll,ll> cnt;
  map<int,bool> rever;
  if (flag) {
    for (auto itr : mp) {
      ll zero = itr.second, one = n - zero;
      if (zero >= one) {
        rever[itr.first] = true;
      } else {
        rever[itr.first] = false;
      }
      ll tmp = max(zero, one);
      ans += itr.first * tmp;
      cnt[itr.first * tmp] = itr.first;
    }
    cout << ans << endl;
    return 0;
  } else {
    for (auto itr : mp) {
      ll zero = itr.second, one = n - zero;
      if (zero >= one) {
        rever[itr.first] = true;
      } else {
        rever[itr.first] = false;
      }
      ll tmp = max(zero, one);
      if (itr.first != kmax) ans += itr.first * tmp;
      cnt[itr.first * tmp] = itr.first;
    }
  }

  map<ll,ll>::reverse_iterator i = cnt.rbegin();
  ll now = 0, itr = 0, tmpans = 0;
  for (; i != cnt.rend(); ++i) {
    if (itr == 0) {
      now += i->second;
      tmpans += i->first;
      continue;
    }
    bool ni = rever[i->second];
    if (ni) ans += i->first;
    else if (now + i->second <= k) {
      now += i->second;
      tmpans += i->first;
    }
    else tmpans += (i->second * n) - i->first;
  }
  
  cout << max(ans,tmpans) << endl;
}
