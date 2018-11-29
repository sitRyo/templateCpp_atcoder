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
  int h,w,k;
  cin >> h >> w >> k;

  if ((w-1) > h) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1; // 始点
  int reach = k - 1;

  // 最大値！！！！

  for (int i = k-1; i <= h; ++i) {
    for (int i = 1; i <= w-1; ++i) {

    }
  }
}
