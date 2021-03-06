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
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll n,k;

/* add your algorithm here */

int main() {
  cin >> n >> k;

  ll dp[n+1], mmax[n+1];
  dp[0] = mmax[0] = 0;

  for (int i = 1; i <= n; ++i) {
    ll b;
    cin >> b;

    if (i < k) {
      dp[i] = dp[i-1] + b;
    } else {
      dp[i] = max(dp[i-1] + b, mmax[i-k]);
    }

    mmax[i] = max(mmax[i-1], dp[i]);
  }

  cout << dp[n] << endl;
}
