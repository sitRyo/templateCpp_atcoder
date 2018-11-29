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

ll S;
ll bits[10];

ll ans = 0;

int main() {
  cin >> S;

  ll temp = S;
  int count = 0;

  while (temp > 0) {
    bits[count] = temp % 10;
    temp /= 10;
    ++count;
  }

  int lim = count - 1;

  for (int i = 0; i < (1 << lim); ++i) {

    ll digits = 1;
    for (int j = 0; j < count; ++j) {

      ans += bits[j] * digits;
      if (j == count - 1) break;

      if ((i >> j) & 1) {
        digits = 1;
      } else {
        digits *= 10;
      }

    }

  }

  cout << ans << endl;
}
