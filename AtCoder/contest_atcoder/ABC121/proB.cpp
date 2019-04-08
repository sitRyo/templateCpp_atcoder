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

int main() {
  int n,m,c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i,m) cin >> b[i];

  ll res = 0;

  rep(i,n) {
    vector<int> a(m);
    ll ans = 0;
    rep(j,m) {
      ll tmp;
      cin >> tmp;
      ans += tmp * b[j];
    }

    if (ans + c > 0) {
      res += 1;
    }
  }

  cout << res << endl;
}
