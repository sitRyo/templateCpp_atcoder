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
  ll t; cin >> t;
  vector<pair<ll,ll> > p;
  rep(i,t) {
    ll a,b;
    cin >> a >> b;
    p.pb(make_pair(a,b));
  }

  for (auto itr : p) {
    ll a = itr.first, b = itr.second;
    if ((a == 1 and b == 1) or (a == 1 and b == 0) or (a == 0 and b == 1)) {
      cout << "YES" << endl;
    } else if (a == 0 and b == 0) {
      cout << "NO" << endl;
    } else if (a == b) {
      cout << "YES" << endl;
    } else if ((a == 1 and b > 1) or (b == 1 and a > 1)) {
      if (a xor b == 0) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    } else if (abs(a-b) > 2) {
      cout << "YES" << endl;
    }
  }
}
