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

typedef unsigned long long ll;

#define INF 10e10
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

ll N;
ll T[MAX + 5];

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  // cout << "gcd: " << a << " " << b << endl;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  ll g = gcd(a, b);
  // cout << "lcm: " << (a * b) / g << endl;
  return a / g * b;
}

int main() {
  cin >> N;
  REP(i,N) cin >> T[i];

  ll ans = 1LL;

  REP(i,N) {
    ll target = T[i];
    // cout << "target: " << target << endl;
    ans = lcm(ans, target);
    // cout << "ans: " << ans << endl;
  }

  cout << ans << endl;
}
