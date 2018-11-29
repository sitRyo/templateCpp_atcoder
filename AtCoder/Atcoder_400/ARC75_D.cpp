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

ll a,b,n;
ll h[100002];

inline bool cal(int mid) {
  ll cnt = 0, sub = a - b;
  rep (i,n) {
    ll tmp = h[i] - mid * b;
    if (tmp <= 0) continue;
    ll rem = ceil((double) tmp / sub);
    cnt += rem;
  }

  return (cnt <= mid) ? true : false;
}

int main() {
  cin >> n >> a >> b;

  rep(i,n) cin >> h[i];

  ll left = 1, right = 1e9;
  while (left <= right) {
    ll mid = (left + right) / 2;
    if (cal(mid)) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << right + 1 << endl;
}
