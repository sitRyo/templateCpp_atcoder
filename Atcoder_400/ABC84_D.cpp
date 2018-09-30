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

vector<bool> SievePrimes(ll n) {
  vector<bool> primes(n,true);
  primes[0] = primes[1] = false;

  ll m = 2;
  while (m*m <= n) {
    if (primes[m]) {
      for (ll i = m; i <= n; i += m) {
        if (i == m) continue;
        if (primes[i]) {
          primes[i] = false;
        }
      }
    }
    m++;
  }

  return primes;
}

int main() {
  ll q;
  cin >> q;

  vector<bool> primes(100010, false);
  vector<int> sum(100010, 0);
  primes = SievePrimes(100010);

  for (int i = 1; i < 100010; i += 2) {
    int j = (i + 1) / 2, s = 0;
    if (primes[i] and primes[j]) {
      s++;
    }
    if (i == 1) {
      sum[i] = s;
    } else {
      sum[i] = sum[i-2] + s;
    }
  }

  for (int i = 0; i < q; ++i) {
    ll l,r;
    cin >> l >> r;

    if (l - 2 < 0) {
      cout << sum[r] - sum[0] << endl;
    } else {
      cout << sum[r] - sum[l-2] << endl;
    }
  }
}
