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
#include <set>
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

int n, k, ans = 1e9;
vector<ll> a, coin;

void dfs(int now, int cnt, int total) {
  if (cnt == k) {
    int cc = 0;
    for (int i = 0; i < coin.size(); ++i) {
      if (coin[i] > total) continue;
      while (total - coin[i] >= 0) {
        cc++;
        total -= coin[i];
      }
    }
    ans = min(ans, cc);
  } else {
    for (int i = 0; i < n; ++i) {
      if (now + 1 + i < n) {
        dfs(now + 1 + i, cnt + 1, total + a[now + i + 1]);
      }
    }
  }
}

int main() {
  cin >> n >> k;
  a.resize(n);
  rep(i, n) {
    cin >> a[i];
  }
  for (int i = 0; i < 10; ++i) {
    coin.push_back(pow(10, i));
    coin.push_back(5 * pow(10, i));
  }

  sort(coin.rbegin(), coin.rend());

  for (int i = 0; i < n; ++i) {
    dfs(i, 1, a[i]);
  }

  cout << ans << endl;
}
