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
  int n, cnt = 0, minj = MOD, pos;

  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    minj = a[i];
    for (int j = i; j < n; ++j) {
      if (a[j] < minj) {
        pos = j;
        minj = a[j];
      }
    }
    if (minj != a[i]) {
      swap(a[i], a[pos]);
      cnt += 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i == n - 1) cout << a[i] << endl;
    cout << a[i] << " ";

  }
  cout << cnt;
}
