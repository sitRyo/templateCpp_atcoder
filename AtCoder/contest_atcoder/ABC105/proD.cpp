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
#include <map>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll n,m;
ll a[100001];

/* add your algorithm here */

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll sum[n+1];
  sum[0] = 0;
  rep(i,n+1) {
    sum[i+1] = (sum[i] + a[i]) % m;
  }

  map<ll, ll> m;
  ll ans = 0;
  for (int i = 1; i < n+1; ++i) {
    ans += m[sum[i]];
    m[sum[i]]++;
  }

  ans += m[0];

  cout << ans << endl;
}
