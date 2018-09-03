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

ll s,c;

/* add your algorithm here */

int main() {
  cin >> s >> c;

  ll ans = 0;
  ll t = 2 * s;

  if (c <= t) {
    ans += c / 2;
    cout << ans << endl;
    return 0;
  }

  ans += s;
  c -= t;

  ans += c / 4;

  cout << ans << endl;
}
