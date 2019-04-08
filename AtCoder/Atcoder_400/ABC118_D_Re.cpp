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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];
  
  int match[10] = {10000, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  string number[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  vector<string> dp(n+100, "");
  dp[0] = "";

  for (int i = 0; i < n; i++) {
    for (auto itr : a) {
      int num = match[itr];
      string temp = dp[i] + number[itr];
      if (dp[i + num] == "") dp[i + num] = temp;
      else if (dp[i + num].size() < temp.size()) {
        dp[i + num] = temp;
      } else if (dp[i + num].size() == temp.size()) {
        dp[i + num] = max(dp[i + num], temp);
      }
    }
  }
  cout << dp[n] << endl;
}
