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
  int n; cin >> n;
  vector<int> a(n);
  double sum = 0;
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }
  double ave = (double)sum / n, tmp;
  ll ans = 150;

  tmp = abs(a[0] - ave);
  ans = 0;

  for (int i = 1; i < n; ++i) {
    if (abs(a[i] - ave) < tmp){
      tmp = abs(a[i]- ave);
      ans = i;
    }
  }

  cout << ans << endl;
}
