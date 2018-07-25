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

int main() {
  cin >> N;

  int t = 0;
  ll ans = 10000000;
  ll i = 0;
  while (i <= N) {
    int count = 0;
    t = N - i;

    while (t > 0) {
      int cc = t % 9;
      t /= 9;
      count += cc;
    }

    int tt = i;
    while (tt > 0) {
      int cc = tt % 6;
      tt /= 6;
      count += cc;
    }

    ++i;

    if (ans > count) ans = count;
  }

  cout << ans << endl;
}
