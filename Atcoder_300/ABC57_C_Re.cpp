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
#define MAX 100

using namespace std;

typedef long long ll;

ll N;

int count_digits (ll n) {
  int count = 0;

  while (n > 0) {
    n /= 10;
    count++;
  }

  return count;
}

int main() {
  cin >> N;

  ll ans = 100;

  for (ll i = 1LL; i * i <= N; i++) {

    ll quo;
    if (N % i) continue;
    quo = N / i;

    ll digit;

    digit = max(count_digits(quo), count_digits(i));

    if (digit < ans) ans = digit;
  }

  printf("%lld\n", ans);

}
