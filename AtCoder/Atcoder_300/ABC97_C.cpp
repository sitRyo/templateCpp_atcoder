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
  int n;
  cin >> n;

  vector<int> num(4);
  for (int i = 0; i < 4; ++i) {
    num[i] = n % 10;
    n /= 10;
  }
  reverse(num.begin(), num.end());
  for (int i = 0; i < (1 << 3); ++i) {
    char op[3];
    int total = num[0];
    for (int j = 0; j < 3; ++j) {
      int bit = (i >> j) & 1;
      if (bit) {
        op[j] = '+';
        total += num[j + 1];
      } else {
        op[j] = '-';
        total -= num[j + 1];
      }
    }
    // cout << total << endl;
    if (total == 7) {
      cout << num[0] << op[0] << num[1] << op[1] << num[2] << op[2] << num[3] << "=7" << endl;
      return 0;
    }
  }
}
