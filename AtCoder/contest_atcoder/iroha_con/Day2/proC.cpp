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

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}


// 最大公約数を求める(ユークリッドの互除法).
ll gcd (ll x, ll y) {
  if (y > x) swap(x,y);
  if (y == 0) return x;
  return gcd(x%y,y);
}

// 最小公倍数を求める(lcm(a,b) = a*b / gcd(a,b)). overflowに気をつけよう
ll lcm (ll x, ll y) {
  ll t = gcd(x,y);
  return (x / t) * y;
}



int main() {
  int n;
  cin >> n;
  vector<ll> h(n);
  set<ll> st;

  rep(i, n) {
    cin >> h[i];
    st.insert(h[i]);
  }

  map<ll, ll> mp;
  int cnt = 1;
  for (auto itr : st) {
    mp[itr] = cnt;
    cnt += 1;
  }

  rep(i, n) {
    cout << mp[h[i]] << endl;
  }
}
