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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  ll cnt = 1;
  ll mmax = 0;
  bool flag = true;
  for (auto &&itr : s) {
    if (itr != 'A') {
      flag = false;
      cnt = 0;
    }
    mmax += cnt;
    cnt += 1;
  }
  
  if (flag) {
    ll len = s.size() * n;
    ll tmp = len * (len + 1) / 2;
    cout << tmp << endl;
    return 0;
  }
  
  ll d1 = 0, d2 = 0;
  ll cnt2 = 1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'B') {
      break;
    }

    d1 += cnt;
    d2 += cnt2;
    cnt2 += 1;
    cnt += 1;
  }

  ll diff = abs(d1 - d2);
  // debug(d1);
  // debug(d2);

  ll ans = mmax + (mmax + diff) * (n - 1);
  cout << ans << endl;
}
