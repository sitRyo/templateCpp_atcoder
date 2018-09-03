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

ll n,m,q;
int p[505][505];

/* add your algorithm here */

int main() {
  cin >> n >> m >> q;

  rep(i,m) {
    int a,b;
    scanf("%d %d", &a, &b);
    p[a][b]++;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[i][j] += p[i-1][j];
      p[i][j] += p[i][j-1];
      p[i][j] -= p[i-1][j-1];
    }
  }

  for (int i = 0; i < q; ++i) {
    int tp,tq;
    scanf("%d %d", &tp, &tq);
    int ans = p[tq][tq] - p[tp-1][tq] - p[tq][tp-1] + p[tp-1][tp-1];
    cout << ans << endl;
  }
}
