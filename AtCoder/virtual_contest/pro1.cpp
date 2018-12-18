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

vector<ll> data;
ll digit = 0;

void dfs(ll n, ll now) {
  if (n > digit) {
    return;
  }

  data.pb(now);
  dfs(n+1, pow(10, n) * 3 + now);
  dfs(n+1, pow(10, n) * 5 + now);
  dfs(n+1, pow(10, n) * 7 + now);
}

int main() {
  ll n;
  cin >> n;
  ll cpy = n;
  while (cpy > 0) {
    cpy /= 10;
    digit++;
  }

  dfs(1,3);
  dfs(1,5);
  dfs(1,7);
  ll res = 0;
  for (auto itr : data) {
    bool a,b,c; a = b = c = false;
    ll cp = itr;
    while (cp > 0) {
      ll t = cp % 10;
      cp /= 10;
      if (t == 3) a = true;
      if (t == 5) b = true;
      if (t == 7) c = true;
    }
    if (a and b and c) {
      if (itr <= n) {res++;}
    }
  }

  cout << res << endl;
}
