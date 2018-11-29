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
  int n; cin >> n;
  vector<ll> data[n];

  int x = -1,y = -1 ,h = -1;
  bool flag = false;
  rep(i,n) {
    ll a,b,c;
    cin >> a >> b >> c;
    if (!flag and c != 0) {
      x = a;
      y = b;
      h = c;
      flag = true;
    }
    data[i].pb(a);
    data[i].pb(b);
    data[i].pb(c);
  }

  if (x == -1) {
    x = data[0][0];
    y = data[0][1];
    h = data[0][2];
  }

  for (int i = 0; i <= 100; ++i) for (int j = 0; j <= 100; ++j) {
    ll H = h + abs(x-i) + abs(y-j);
    if (H < 1) {
      continue;
    }
    bool flag = true;
    for(int k = 0; k < n; ++k) {
      ll tmp = H - abs(data[k][0] - i) - abs(data[k][1] - j);
      if (tmp < 0) tmp = 0;
      if (tmp != data[k][2]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << i << " " << j << " " << H << endl;
    }
  }
}
