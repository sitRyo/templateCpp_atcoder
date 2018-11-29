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
  int t; cin >> t;
  rep(i,t) {
    ll n,x,y,d; cin >> n >> x >> y >> d;

    ll tmp1 = abs(y - x);
    if (tmp1 % d == 0) {
      cout << tmp1 / d << endl;
    } else {
      ll dx = ceil((double)(x - 1) / d) , dy = ceil((double)(n - x) / d);
      vector<ll> left,right;

      ll tt = 1;
      while (tt <= n) {
        if (tt == n) break;
        left.pb(tt);
        tt += d;
      }
      left.pb(n);
      tt = n;
      while (tt >= 1) {
        if (tt == 1) break;
        right.pb(tt);
        tt -= d;
      }
      right.pb(1);

      ll tar1 = -1, tar2 = -1;
      ll c1 = -1,c2= -1;
      for (int i = 0; i < left.size(); ++i) {
        if (left[i] == y) {
          tar1 = i;
          c1 = dx + tar1;
        }
      }

      for (int i = 0; i < right.size(); ++i) {
        if (right[i] == y) {
          tar2 = i;
          c2 = dy + tar2;
        }
      }

      if (tar1 == -1 and tar2 == -1) {
        cout << -1 << endl;
      } else {
        if (c1 != -1 and c2 != -1) {
          cout << min(c1,c2) << endl;
        } else if (c1 != -1) {
          cout << c1 << endl;
        } else {
          cout << c2 << endl;
        }
      }
    }
  }
}
