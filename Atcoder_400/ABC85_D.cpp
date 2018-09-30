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
#define END cout << endl
#define MOD 1000000007
#define pb push_back

int main() {
  ll n,h;
  cin >> n >> h;

  vector<ll> b(n,0),a(n,0);
  rep(i,n) {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  auto itr = upper_bound(b.begin(), b.end(), a.back());
  ll st = itr - b.begin();

  ll ans = 0;
  for (int i = b.size()-1; i >= st; --i) {
    if (h <= 0) break;
    ans++;
    h -= b[i];
  }
  if (h > 0) {
    ans += h / a.back();
    ans += (h % a.back() > 0) ? 1 : 0;
  }

  cout << ans << endl;
}
