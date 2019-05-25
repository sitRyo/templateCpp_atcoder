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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

using pi = pair<ll, ll>;

int main() {
  ll n,m;
  cin >> n >> m;

  map<ll, ll> mp;
  vector<pair<pi, ll> > rail(m);

  vector<pair<ll,ll> > v[n + 1];
  pair<ll, ll> p;
  ll t;
  rep(i,m) {
    cin >> p.first >> p.second >> t;
    rail[i] = make_pair(p, t);
    v[p.first].push_back(make_pair(p.second, t));
  }

  ll ans = 0;
  for (auto itr : rail) {
    ll left = itr.first.first, second = itr.first.second, len = itr.second;
    for (auto it : v[second]) {
      if (2540 - len - it.second == 0) ans += 1;
    }
  }

  cout << ans << endl;
}
