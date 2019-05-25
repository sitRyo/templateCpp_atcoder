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

ll A[365];
int n, m, k;

ll dp(int i, int j) {
  if (j == 0) {
    if (n <= i + k - 1) return 0;
    else return -INF;
  }

  ll ret = -INF;
  for (int t = 0; t < k and i + t < n; ++k) {
    ret = max(ret, A[i + k] + dp(i + k + 1, j - 1));
  }

  return ret;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  rep(i, n) cin >> A[i];

  cout << max(dp(0, m), -1LL) << endl;
}
