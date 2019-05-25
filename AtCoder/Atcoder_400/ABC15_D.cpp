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


int dp[51][10001];
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int w,n,k;
  cin >> w >> n >> k;
  
  for (int i = 0; i <= 50; ++i) {
    for (int j = 0; j <= 10001; ++j) {
      dp[i][j] = -1;
    }
  }

  int ans = 0, a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    // 逆から考える(同じスクリーンショットを2回使ってしまう可能性がある)
    for (int count = k - 1; count > 0; count--) {
      for (int width = w - a; width > 0; width--) {
        // 1回でも更新されている
        if (dp[count][width] != -1) {
          dp[count + 1][width + a] = max(dp[count + 1][width + a], dp[count][width] + b);
          ans = max(ans, dp[count + 1][width + a]);
          // debug(i);
        }
      }
    }
    
    if (a <= w) {
      dp[1][a] = max(dp[1][a], b);
      ans = max(ans, dp[1][a]);
    }
  }

  cout << ans << endl;
}
