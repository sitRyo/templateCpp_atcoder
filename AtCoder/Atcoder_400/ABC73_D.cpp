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

#define N 10000

ll cost[N][N];

int main() {
  int n, m, r;
  cin >> n >> m >> r;

  vector<ll> R(r), A(m), B(m), C(m);
  rep(i, r) cin >> R[i];
  

  rep(i, m) {
    int a,b,c;
    cin >> A[i] >> B[i] >> C[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) cost[i][j] = 0;
      else cost[i][j] = INF;
    }
  }

  for (int i = 0; i < m; ++i) {
    cost[A[i]][B[i]] = C[i];
    cost[B[i]][A[i]] = C[i];
  }

  for (ll k = 1; k <= n; ++k) {
    for (ll i = 1; i <= n; ++i) {
      for (ll j = 1; j <= n; ++j) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }

  sorti(R);

  ll ans = INF;

  do {
    ll tmp = 0;
    for (int i = 0; i < r - 1; ++i) {
      tmp += cost[R[i]][R[i + 1]];
    }
    ans = min(ans, tmp);
  } while (next_permutation(R.begin(), R.end()));

  cout << ans << endl;
}
