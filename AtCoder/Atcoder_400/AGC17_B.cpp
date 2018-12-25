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
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;

  ll i = 0, sub = abs(a-b);
  while (i * 2 <= n - 1) {
    ll right = d * (n - 1 - i * 2);
    ll left = c * (n - 1 - i * 2);

    ll ma = abs(c-d) * i;
    if (left - ma <= sub and sub <= right + ma) {
      cout << "YES" << endl;
      exit(1);
    }
    i++;
  }
  cout << "NO" << endl;
}
