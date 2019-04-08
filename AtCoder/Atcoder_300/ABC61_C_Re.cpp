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
  int n,k;
  cin >> n >> k;

  map<ll, ll> mp;

  vector<ll> a(n), b(n);
  rep(i,n) {
    cin >> a[i] >> b[i];
    mp[a[i]] += b[i];
  }
  ll t;
  for (auto itr : mp) {
    t = itr.first;
    if (k - itr.second <= 0) {
      cout << itr.first << endl;
      return 0;
    } else {
      k -= itr.second;
    }
  }

  if (k > 0) {
    cout << t << endl;
  }
}
