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
  string s;
  cin >> n;
  cin >> s;

  vector<ll> sums(n + 1, 0), sumb(n + 1, 0);

  ll ans = INF, cntlast = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.')  {
      sums[i + 1] = sums[i] + 1;
      sumb[i + 1] = sumb[i];
    } else {
      sumb[i + 1] = sumb[i] + 1;
      sums[i + 1] = sums[i];
    }
    // cout << sumb[i + 1] << " " << sums[i + 1] << endl;
  }

  bool flag = false;
  int pre = 0;
  for (int i = 0; i < n; ++i) {
    ll tmp = INF;
    if (s[i] == '#' and !flag) {
      flag = true;
      pre = i;
    } else if (s[i] == '#' and flag) {
      // white, black,  black, black,  white, white
      tmp = sumb[i] - sumb[pre] + sums[n] - sums[i];
      tmp = min(sums[i] - sums[pre]  + sums[n] - sums[i], tmp);
      tmp = min(tmp, sumb[i] - sumb[pre] + sumb[n] - sumb[i]);
    }

    ans = min(ans, tmp);
  }
  
  if (ans == INF and flag) {
    ans = min(sumb[n] - sumb[pre], sums[n] - sums[pre]);
  } else if (ans == INF and !flag) {
    ans = 0;
  }
  cout << ans << endl;
}
