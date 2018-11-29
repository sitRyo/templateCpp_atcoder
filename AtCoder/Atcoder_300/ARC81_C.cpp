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

ll n;

/* add your algorithm here */

int main() {
  cin >> n;
  vector<ll> a(n,0);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());

  ll res = 0, e1 = 0, e2 = 0, cnt = 0;
  for (int i = n-1; i >= 0; --i) {
    cnt++;
    if (i == 0) {
      if (cnt == 2) {
        e2 = a[i];
      }
      break;
    }
    if (cnt == 2) {
      if (!e1) e1 = a[i];
      else if (!e2) {
        e2 = a[i];
        break;
      }
      cnt = 0;
    } else if (a[i] != a[i-1]) {
      cnt = 0;
    }
  }

  res = e1 * e2;
  cout << res << endl;
}
