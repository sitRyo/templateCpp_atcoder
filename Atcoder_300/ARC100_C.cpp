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

  rep(i,n) {
    ll b;
    cin >> b;
    a.pb(b - (i+1));
  }

  sort(a.begin(), a.end());
  ll b;

  if (!a.size() % 2) {
    ll t = a.size() / 2;
    b = (a[t] + a[t + 1]) / 2;
  } else {
    b = a[a.size() / 2];
  }

  ll ans = 0;
  rep(i,n) {
    ll t = abs(a[i] - b);
    ans += t;
  }

  cout << ans << endl;
}
