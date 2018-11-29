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

int main() {
  ll q,h,s,d,n;
  cin >> q >> h >> s >> d >> n;

  if (2 * q < h) {
    h = 2 * q;
  }

  if (4 * q < s) {
    s = 4 * q;
  }

  if (2 * h < s) {
    s = 2 * h;
  }

  if (8 * q < d) {
    d = 8 * q;
  }

  if (4 * h < d) {
    d = 4 * h;
  }

  if (2 * s < d) {
    d = 2 * s;
  }

  ll ans = 0;
  if (n % 2 == 0) {
    ans += (n / 2) * d;
  } else {
    ans += (n / 2) * d;
    ans += s;
  }

  cout << ans << endl;
}
