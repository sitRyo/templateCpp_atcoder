/*
 * No.754 畳み込みの和
 */ 

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
  vector<ll> a(n + 1), b(n + 1), sum(n + 2);
  rep(i, n + 1) {
    cin >> a[i];
  }

  rep(i, n + 1) {
    cin >> b[i];
  }

  sum[0] = 0;
  for (int i = 0; i < n + 1; ++i) {
    sum[i + 1] += (sum[i] + b[i]) % MOD;
  }

  ll ans = 0;
  for (int i = 0; i < n + 1; ++i) {
    ans += a[i] * (sum[n + 1 - i] - sum[0] + MOD) % MOD;
  }

  cout << ans % MOD << endl;
}
