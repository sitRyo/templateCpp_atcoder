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

void solve(double x) {
  if (x == 0) {
    cout << "Y " << 0.0 << " " << 0.0 << endl;
    return;
  }
  if (x < 4) {
    cout<< "N" << endl;
    return;
  }

  double D = sqrt(x * ll(x - 4));
  double a = (x + D) / 2.0;
  double b = (x - D) / 2.0;

  cout << "Y " << a << " " << b << endl;
}

int main() {
  cout << fixed << setprecision(9);

  int tc = 0;
  cin >> tc;

  ll x;
  rep(i,tc) {
    cin >> x;
    solve(x);
  }
}
