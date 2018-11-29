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

#define INF 10e10
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll N;
ll m;

int count_digits(ll n) {
  int digits = 0;

  while (n > 0) {
    n /= 10;
    digits++;
  }

  return digits;
}


int main() {
  cin >> N;
  ll n = N;
  int count = 0;
  int ans = 100;

  for (ll i = 1LL; i * i <= N; i++) {

    if (N % i) continue;
    n = N / i;

    count = max(count_digits(i), count_digits(n));

    if (count < ans) {
      ans = count;
    }

  }

  printf("%d\n", ans);
}
