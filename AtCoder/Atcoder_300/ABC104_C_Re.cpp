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

typedef pair<int,ll> pl;

int main() {
  ll d,g; cin >> d >> g;
  vector<pl> pc;
  rep(i,d) {
    ll p,c; cin >> p >> c;
    pc.pb(make_pair(p,c));
  }

  ll res = 1001;
  for (int b = 0; b < (1 << d); ++b) {

    ll tmp = g, cnt = 0;
    for (int i = 0; i < d; ++i) {
      if ((b >> i) & 1) {
        int point = 100 * (i+1);
        tmp -= pc[i].second + pc[i].first * point;
        cnt += pc[i].first;
      }
    }

    cout << "cnt:" << res << endl;

    if (tmp <= 0) {
      res = min(cnt, res);
      continue;
    }

    printf("time: %d, tmp: %d\n", b, tmp);

    for (int i = d-1; i >= 0; --i) {
      cout << "in" << endl;
      bool flag = false;
      if (!((b >> i) & 1)) {
        cout << i << endl;
        for (int j = 0; j < pc[i].first; ++j) {
          tmp -= 100 * (i+1);
          cnt++;
          if (tmp <= 0) {
            res = min(cnt, res);
            flag = true;
            break;
          }
        }
      }
      if (flag) {
        break;
      }
      tmp -= pc[i].second;
      if (tmp <= 0) {
        res = min(cnt, res);
        flag = true;
        break;
      }
    }
  }

  cout << res << endl;

}
