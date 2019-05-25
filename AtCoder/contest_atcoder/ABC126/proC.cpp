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
#include <iomanip>
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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

int main() {
  int n, k;
  cin >> n >> k;
  double table[10000];
  double ans = 0;
  cout << fixed << setprecision(12) ;

  table[0] = 1.0000000000;
  for (int i = 0; i < 10000-1; ++i) {
    table[i+1] = table[i] * (0.5);
  }

  for (int i = 1; i <= n; ++i) {
    int t = i, cnt = 0;
    for (;t < k; t*=2) {
      cnt += 1;
    }
    double tt = (double)1 / n;
    // cout << (double)1 / n << endl;
    ans += (double)(tt * table[cnt]);
    // cout << ans << endl;
  }

  cout << ans << endl;
}
