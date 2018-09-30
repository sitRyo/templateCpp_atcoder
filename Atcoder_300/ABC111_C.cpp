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

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

typedef pair<int, int> pi;

int main() {
  ll n;
  cin >> n;

  vector<pi> e(100001), o(100001);
  for (int i = 1; i <= n; ++i) {
    ll t; cin >> t;
    if (i % 2 == 0) {
      e[t].second = t; e[t].first++;
    } else {
      o[t].second = t; o[t].first++;
    }
  }

  sorti(e), sorti(o);

  if (e.back() == o.back()) {
    cout << min(n - e[100000].first - o[99999].first, n - o[100000].first - e[99999].first);
  } else {
    cout << n - e.back().first - o.back().first << endl;
  }
}
