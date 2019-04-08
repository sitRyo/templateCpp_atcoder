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
  ll n;
  cin >> n;
  vector<ll> c(n), m(n,0);
  vector<ll> v[n];
  map<ll,ll> mp;

  rep(i,n) {
    scanf("%lld", c[i]);
  }

  for (int i = 0; i < n; ++i) {
    if (v[i].empty()) {
      v[i].push_back(c[i]);
    } else if (v[i].back() != i - 1) {
      v[i].push_back(c[i]);
    }
  }

  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < v[i].size()-1; ++j) {
      if (m[v[i][j]] == 0 or m[v[i][j]] == 0) {
        
      }
    }
  }
}
