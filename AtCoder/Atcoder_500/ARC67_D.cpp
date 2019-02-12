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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  rep(i,n) cin >> x[i];

  ll ans = 0;
  for (int i = 0; i < n-1; ++i) {
    ll d = x[i+1] - x[i];
    ll costA = d * a;
    if (costA < b) {
      ans += costA;
    } else {
      ans += b;
    }
  }

  cout << ans << endl;
  
}
