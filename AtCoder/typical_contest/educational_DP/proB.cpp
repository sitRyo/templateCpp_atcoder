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

ll dp[100010];
int n,k;

int main() {
  cin >> n >> k;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];

  dp[0] = 0;
  
  // loop
  for (int i = 1; i < n; ++i) {
    dp[i] = INF;
    for (int s = 1; s <= k; ++s) {
      if (i - s >= 0) {
        dp[i] = min(dp[i], dp[i - s] + abs(h[i] - h[i - s]));
      } else {
        break;
      }
    }
  }

  cout << dp[n-1] << endl;
}
