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
  ll n; cin >> n;
  vector<ll> a(n), b(n), diff(n);
  ll suma = 0, sumb = 0;
  rep(i,n) {
    cin >> a[i];
    suma += a[i];
  }
  rep(i,n) {
    cin >> b[i];
    sumb += b[i];
  }

  if (suma < sumb) {
    cout << -1 << endl;
    return 0;
  }

  ll remain = suma - sumb;

  for (int i = 0; i < n; ++i) {
    diff[i] = a[i] - b[i];
  }

  ll ans = 0;
  sorti(diff);
  for (int i = 0; i < n; ++i) {
  
    if (diff[i] < 0) {
      ans++;
      continue;
    }

    if (remain - diff[i] < 0) {
      ans += n - i;
      break;
    } else {
      remain -= diff[i];
    }
  }

  cout << ans << endl;
}
