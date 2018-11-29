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

int N;
ll ans = 0;
ll ct = 0, ca = 0;

ll T[1001], A[1001];

int main() {
  cin >> N;
  rep(i,N) scanf("%lld %lld", &T[i], &A[i]);

  ct = T[0]; ca = A[0];

  for (int i = 1; i < N; ++i) {

    ll x,y;
    x = ((ct % T[i]) > 0) ? (ct / T[i]) + 1 : ct / T[i];
    y = ((ca % A[i]) > 0) ? (ca / A[i]) + 1 : ca / A[i];


    ll n = max(x,y);

    ct = n * T[i]; ca = n * A[i];
  }

  ans = ct + ca;
  cout << ans << endl;
}
