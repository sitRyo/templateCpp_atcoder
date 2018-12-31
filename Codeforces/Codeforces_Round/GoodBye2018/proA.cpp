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
  ll y,b,r;
  cin >> y >> b >> r;

  ll ry,rb,rr, res = 0;
  for (int i = 1; i <= y; ++i) {
    if (b >= i + 1 and r >= i + 2) {
      ry = i;
      rb = i + 1;
      rr = i + 2;
      res = ry + rb + rr;
    } else {
      break;
    }
  }

  cout << res << endl;
}
