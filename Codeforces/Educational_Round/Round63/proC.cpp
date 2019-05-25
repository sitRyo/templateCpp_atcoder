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
#include <set>
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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

ll gcd (ll x, ll y) {
  if (y > x) swap(x,y);
  if (y == 0) return x;
  return gcd(x%y,y);
}

int main() {
  ll n,m;
  cin >> n >> m;
  map<ll,ll> mp;
  vector<ll> x(n), p(m);
  
  rep(i,n) cin >> x[i];
  rep(i,m) {
    cin >> p[i];
  }

  vector<ll> diff(n - 1);
  for (int i = 0; i < n-1; ++i) {
    diff[i] = x[i + 1] - x[i];
  }

  ll t = diff.front();
  for (int i = 1; i < n - 1; ++i) {
    t = gcd(t, diff[i]);
  }
  // debug(t);
  for (int i = 0; i < m; ++i) {
    if (t % p[i] == 0) {
      cout << "YES" << endl;
      cout << x[0] << " " << i+1 << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}
