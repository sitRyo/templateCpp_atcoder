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
  int n; scanf("%d", &n);
  vector<int> a(n);
  map<int,int> mp;
  rep(i,n) {
    scanf("%d", &a[i]);
    mp[a[i]]++;
  }

  ll res = 0, d = 0;

  for (auto itr : mp) {
    if (itr.second >= 3) {
      if (itr.second % 2 == 1) {
        res += itr.second - 1;
      } else {
        res += itr.second - 2;
        d += 1;
      }
    } else if (itr.second == 2) {
      d += 1;
    }
  }

  if (d) {
    if (d % 2 == 0) {
      res += d;
    } else {
      int s = d - 1;
      res += s;
      res += 2;
    }
  }
  printf("%lld\n", n - res);
}
