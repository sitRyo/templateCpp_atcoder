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

#define INF 10e18 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  string s,t,ss,tt;
  cin >> ss;
  cin >> tt;
  int n = ss.size(), m = tt.size();

  vector<vector<int> > dp(3001, vector<int>(3001,0)), pre(dp);
  // dp[i][j] = s1...si, t1...tjまでのLCS
  // vectorのコピーコンストラクタ -> 同じ要素数を確保
  
  s = '+' + ss; // s[0] != t[0] and s[i] != t[0] and s[0] != t[i]
  t = '*' + tt;

  for (int si = 1; si <= n; ++si) {
    for (int ti = 1; ti <= m; ++ti) {
      if (s[si] == t[ti]) {
        dp[si][ti] = dp[si-1][ti-1] + 1;
        pre[si][ti] = 1;
      } else if (dp[si-1][ti] > dp[si][ti-1]) {
        dp[si][ti] = dp[si-1][ti];
        pre[si][ti] = 2;
      } else {
        dp[si][ti] = dp[si][ti-1];
        pre[si][ti] = 3;
      }
    }
  }

  // cout << dp[n][m] << endl;
  // 復元
  string ans = "";
  int i = n, j = m;
  while (i >= 1 and j >= 1) {
    if (pre[i][j] == 1) {
      ans += s[i];
      i--, j--;
    } else if (pre[i][j] == 2) {
      i--;
    } else {
      j--;
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto itr : ans) {
    cout << itr;
  } END;
}
