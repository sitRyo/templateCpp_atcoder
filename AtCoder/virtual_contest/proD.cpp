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
  string s;
  ll ans = 0;

  cin >> s;
  vector<bool> bits(s.size());

  rep(i,s.size()) {
    bits[i] = (s[i] == '0') ? false : true;
  }

  int l = 0, r = s.size(), tmp = 0;
  bool now = bits[0];

  for (int i = 0; i < r; ++i) {
    if (bits[i] == now) {
      tmp += 1;
    } else {
      tmp += 1;
      ans = max<ll>(tmp, ans);
      tmp = 1;
      now = bits[i];
    }
  }

  if (tmp > 0) {
    ans = max<ll>(tmp,ans);
  }
  cout << ans << endl;
}
