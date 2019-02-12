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

void mul(ll& a, ll& b) {
  a = a * b % MOD;
}

int main() {
  int n,m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  sortd(a);
  sortd(b);

  a.pb(-1);
  b.pb(-1);

  ll apt = 0, bpt = 0, num = n * m;
  ll ans = 1;
  while (num > 0) {
    if (a[apt] == num and b[bpt] == num) {
      apt++;
      bpt++;
    } else if (a[apt] == num) {
      apt++;
      mul(ans, bpt);
    } else if (b[bpt] == num) {
      bpt++;
      mul(ans, apt);
    } else {
      ll tmp = apt * bpt - (n * m - num);
      mul(ans, tmp);
    }
    num -= 1;
  }
  cout << ans << endl;
}
