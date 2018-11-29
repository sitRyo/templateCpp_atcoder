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

ll res = 0;

int main() {
  int n; scanf("%d", &n);
  vector<ll> a(n+1,0);
  for (int i = 1; i <= n; ++i) {
    ll t;
    scanf("%lld", &t);
    a[i] = a[i-1] + t;
  }

  /*
  swap(a[0], a.back());
  a.pop_back();
  */

  map<ll,ll> mp;
  for (int i = 0; i <= n; ++i) {
    mp[a[i]]++;
  }

  for (auto itr : mp) {
    //cout << itr.second << endl;
    res += ((itr.second - 1) * itr.second) / 2;
  }
  printf("%lld\n", res);
}
