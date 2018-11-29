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

int main() {
  ll n,q, a[100001], b[100001],x,y,l,r;
  cin >> n >> q;
  string s;
  cin >> s;
  b[0] = 1;
  for (int i = 1; i <= 100000; ++i) b[i] = (b[i-1] * 2) % MOD;
  a[0] = (s[0] == '1') ? 1 : 0;
  for (int i = 0; i < n; ++i) {
    a[i] = (s[i] == '1') ? a[i-1] + 1 : a[i-1] + 0;
  }

  rep(i,q) {
    cin >> l >> r;
    r--, l--;

    x = b[a[r]- a[l-1]] - 1;
    y = b[r-l+1 - (a[r] - a[l-1])];
    cout << (x * y) % MOD << endl;
  }
}
