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

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  ll n,ma,mb;
  cin >> n >> ma >> mb;
  ll ans = 1;

  vector<ll> a(n), b(n), c(n);
  rep(i,n) {
    cin >> a[i] >> b[i] >> c[i];
    ans += c[i];
  }

  int dp[n+1][4001][4001];
  dp[0][0][0] = 0;

  for (int i = 0; i < n; ++i) {
    
  }
}
