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
  ll n;
  cin >> n;
  vector<ll> t(5);
  bool flag = true;
  rep(i, 5) {
    cin >> t[i];
    if (t[i] < n) flag = false;
  }

  if (flag) {
    cout << 5 << endl;
    return 0;
  }

  ll ans = 0;
  vector<ll> cnt(5);
  pair<ll,ll> p;
  p.first = -1; p.second = -1;
  for (int i = 0; i < 5; ++i) {
    cnt[i] = n / t[i];
    if (n % t[i] > 0) cnt[i] += 1;
    if (p.first < cnt[i]) {
      p.second = i + 1;
      p.first = cnt[i];
    }
  }

  ans = 4 + p.first;
  cout << ans << endl;
}
