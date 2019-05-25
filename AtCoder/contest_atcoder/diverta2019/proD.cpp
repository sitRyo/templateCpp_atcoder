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

template<typename T>
set<T> div_count(T x) {
  set<T> st;
  for (ll i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      st.insert(i);
      st.insert(x/i);
    }
  }
  return st;
}
int main() {
  ll n;
  cin >> n;
  set<ll> st = div_count(n);
  ll ans = 0;
  for (auto itr : st) {
    // debug(itr);
    ll t = itr - 1;
    if (t == 0 or t == 1) continue;
    if (n % t == n / t) ans += itr - 1;
  }

  cout << ans << endl;
}
