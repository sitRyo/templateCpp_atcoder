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
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define dubug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

int main() {
  ll n;
  cin >> n;

  vector<ll> p(n + 1, 0);

  rep(i, n) cin >> p[i];

  for_each(p.begin(), p.end(), [](auto & v) { v--;});

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (p[i] == i) {
      swap(p[i], p[i + 1]);
      ans += 1;
    }
  }

  cout << ans << endl;
}
