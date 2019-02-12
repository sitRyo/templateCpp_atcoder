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
  ll k,a,b;
  cin >> k >> a >> b;

  if (b <= a) {
    cout << k + 1 << endl;
    return 0;
  }

  if (k <= a) {
    cout << k + 1 << endl;
    return 0;
  }

  if (b - a == 1) {
    cout << k + 1 << endl;
    return 0;
  }

  // k > a & a > b
  ll remain = k - a + 1;
  ll kaisuu = remain / 2;
  ll sub = b - a;
  ll ans = 0;
  if (remain % 2 == 0) {
    ans = sub * kaisuu + a;
  } else {
    ans = sub * kaisuu + a + 1;
  }

  cout << ans << endl;
}
