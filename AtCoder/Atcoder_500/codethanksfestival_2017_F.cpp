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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> dp_pre(200010, 0), dp_aft(200010, 0);
  dp_pre[0] = 1;
  sorti(a);
  int limit = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= limit*2; ++j) {
      dp_aft[j] = 0;
    }
    for (int j = 0; j <= limit*2; ++j) {
      dp_aft[j] += dp_pre[j] % MOD;
      dp_aft[j ^ a[i]] += dp_pre[j] % MOD;
    }

    limit |= a[i];
    swap(dp_pre, dp_aft);
  }

  cout << dp_pre[k] % MOD << endl;
}
