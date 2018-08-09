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

#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

int n,a,b;
ll v[51];
ll ans = 0, mmax = 0;
ll dp[51][51];

/* add your algorithm here */

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) cin >> v[i];

  dp[0][0] = 0;

  for (int )

  for (int i = 1; i < b; ++i) {
    for (int j = 0; j < i; ++j) {
      dp[i+1][j+1] = max(dp[i][j] + v[i], dp[i][j+1]);
    }
  }
}
