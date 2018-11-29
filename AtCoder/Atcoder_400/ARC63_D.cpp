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
  ll n,t;
  cin >> n >> t;
  vector<ll> a(n,0);

  rep(i,n) {
    cin >> a[i];
  }

  vector<ll> ans;
  ll mmax = -1, mmin = a[0];
  for (int i = 1; i < n; ++i) {
    ll tmp = a[i], dif;
    if (tmp > mmin) {
      dif = tmp - mmin;
      if (dif >= mmax) {
	ans.pb(dif);
	mmax = dif;
      } 
    } else {
      mmin = min(tmp, mmin);
    }
  }

  sorti(ans);
  
  ll res = 0;
  if (ans.size() <= 1) {
    res = (ans.empty()) ? 0 : 1;
  } else {
    ll b = ans.back();
    for (auto itr : ans) {
      if (itr == b) {
	res += 1;
      }
    }
  }

  cout << res << endl;
}
