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

using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
int lcs(string s,string t){
  int n=s.size(),m=t.size();
  s+='$';t+='%';
  vector<vector<int> > dp(n+2,vector<int>(m+2,-(n+m)));
  dp[0][0]=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      chmax(dp[i+1][j],dp[i][j]);
      chmax(dp[i][j+1],dp[i][j]);
      chmax(dp[i+1][j+1],dp[i][j]+(s[i]==t[j]));
    }
  }
  return dp[n][m];
}
//END CUT HERE

int main() {
  string s, t;
  cin >> s;
  cin >> t;

  int ans = lcs(s, t);
  cout << ans + 1 << endl;
}
