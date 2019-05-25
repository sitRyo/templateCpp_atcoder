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
#include <map>
#include <cmath>
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

template <class T>
vector<T> factorize(T n) {
  vector<T> res;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      while (n % i == 0) n /= i;
    }
  }

  if (n != 1) res.push_back(n);
  return res;
}

int main() {
  ll n;
  cin >> n;

  vector<ll> res = factorize(n);
  
  int m = res.size(), ans = 0;
  for (int bit = 1; bit < (1 << m); ++bit) {
    int pop_count = __builtin_popcount(bit);
    int mul = 1;
    for (int i = 0; i < m; ++i) {
      if (bit >> i & 1) mul *= res[i];
    }
    if (pop_count % 2 == 1) ans += n / mul;
    else ans -= n / mul;
  }

  ans = n - ans;
  cout << ans << endl;
}
