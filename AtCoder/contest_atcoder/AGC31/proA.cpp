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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;

  map<char, ll> mp;

  ll len = 1;
  ll ans = 0;

  for (int i = 0; i < n; ++i) {
    char t = s[i];
    mp[t] += 1;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (c == t) continue;
      if (mp[c] > 0) {
        len *= mp[c] + 1;
      }
    }

    ans += len % MOD;
    cout << ans << endl;
    ans %= MOD;
    len = 1;
  }

  printf("%lld\n", ans);
}
