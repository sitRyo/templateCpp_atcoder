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
#include <unordered_map>
#include <set>
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

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n), suma(n+1, 0), sumb(n+1, 0);
  rep(i, n) {
    cin >> a[i];
    suma[i+1] += suma[i] + a[i];
  }
  rep(i, n) {
    cin >> b[i];
    sumb[i+1] += sumb[i] + b[i];
  }

  ll ans = -1;
  for (int i = 1; i < n+1; ++i) {
    ll tmpa = suma[i], tmpb = sumb[n] - sumb[i-1];
    chmax(ans, tmpa + tmpb);
  }

  cout << ans << endl;
}
