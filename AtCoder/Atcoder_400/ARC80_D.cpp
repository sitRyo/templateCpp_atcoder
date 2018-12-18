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
  int h,w,n; cin >> h >> w >> n;
  vector<pair<int,int> > a(n);
  rep(i,n) {
    pair<int,int> p;
    cin >> p.second;
    p.first = i + 1;
    a[i] = p;
  }

  int res[h][w];
  ll count = 0, row = 0;
  bool flag = true;
  for (auto itr : a) {
    for (int i = 0; i < itr.second; ++i) {
      res[row][count] = itr.first;
      if (flag) {
        count += 1;
        if (count >= w) {
          row += 1;
          count = w-1;
          flag = false;
        }
      } else {
        count -= 1;
        if (count < 0) {
          row += 1;
          count = 0;
          flag = true;
        }
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << res[i][j] << " ";
    }
    END;
  }
}
