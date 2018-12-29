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

int main() {
  string s; cin >> s;

  vector<int> a(3,0);
  rep(i,s.size()) {
    char tmp = s[i];
    switch (tmp) {
      case 'a': {
        a[0] += 1;
        break;
      }
      case 'b': {
        a[1] += 1;
        break;
      }
      case 'c': {
        a[2] += 1;
      }
    }
  }
  ll mi = 1000000, ma = -10000;
  for (int i = 0; i < 3; ++i) {
    mi = min<ll>(mi, a[i]);
    ma = max<ll>(ma, a[i]);
  }

  printf((abs(mi-ma)) <= 1 ? "YES\n" : "NO\n");
}
