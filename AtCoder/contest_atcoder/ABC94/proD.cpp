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
  ll n;
  cin >> n;
  vector<ll> a(n,0);

  rep(i,n) {
    cin >> a[i];
  }

  sorti(a);
  vector<ll> b(n,0);

  ll tmp = -1;
  pair<ll,ll> ans;

  ll tar = a.back();
  ll half = tar / 2;
  for (int i = n-2; i >= 0; --i) {
    ll t = tar - a[i];
    if (t > half) {
      t = tar - t;
    }
    if (t > tmp) {
      tmp = t;
      ans = make_pair(tar, a[i]);
    }
  }

  cout << ans.first << " " << ans.second << endl;
}
