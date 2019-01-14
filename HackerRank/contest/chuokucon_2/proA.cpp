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
  int h,m;
  cin >> h >> m;

  ll ans = 0;
  if (h == 12 and m == 0) {
    cout << 0 << endl;
  } else if (h < 12) {
    ans = (12 - h) * 60 - m;
    cout << ans << endl;
  } else {
    ans = (24 - h) * 60 - m + 12 * 60;
    cout << ans << endl;
  }
}
