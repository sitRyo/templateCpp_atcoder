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
  ll a,b,c;
  cin >> a >> b >> c;

  if (!(a % 2 == 0 and b % 2 == 0 and c % 2 == 0)) {
    cout << 0 << endl;
    return 0;
  }

  if (a == b and b == c) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  while (true) {
    ll ta = b / 2 + c / 2;
    ll tb = a / 2 + c / 2;
    ll tc = a / 2 + b / 2;
    if (ta % 2 == 0 and tb % 2 ==0 and tc % 2 == 0) {
      ans += 1;
    } else {
      break;
    }

    a = ta; b = tb; c = tc;
  }

  cout << ans+1 << endl;
}
