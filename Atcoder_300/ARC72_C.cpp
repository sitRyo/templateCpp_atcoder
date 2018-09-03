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
vector<ll> a;

/* add your algorithm here */

int main() {
  cin >> n;
  ll sum[n+1];
  ll x;

  rep(i,n) {
    sum[i] = 0;
  }
  cin >> x;
  a.pb(x);
  sum[0] = x;
  for (int i = 1; i < n; ++i) {
    cin >> x;
    a.pb(x);
    sum[i] = sum[i-1] + x;
  }

  bool odd,even;
  bool flag = (sum[0] >= 0) ? true : false;

  if (flag) {

  }

  ll ch = 0;
  for (int i = 1; i < n; ++i) {

  }

}
