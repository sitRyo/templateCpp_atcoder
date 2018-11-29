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
  ll buc[100002];
  rep(i,100002) buc[i] = 0;
  ll a, m = -1;
  rep(i,n) {
    cin >> a;
    buc[a]++;
    m = max(m,a);
  }

  ll res = -1;
  for (ll i = 0; i <= m; ++i) {
    ll sum;
    if (i == 0) {
      sum = buc[i] + buc[i+1];
    } else {
      sum = buc[i-1] + buc[i] + buc[i+1];
    }
    res = max(res, sum);
  }

  cout << res << endl;
}
