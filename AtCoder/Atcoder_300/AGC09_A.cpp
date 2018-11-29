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
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n,0), b(n,0);

  rep(i,n) {
    scanf("%d %d", &a[i], &b[i]);
  }

  ll sum = 0;
  for (int i = n-1; i >= 0; --i) {
    a[i] += sum;
    int di = (a[i] % b[i]);
    if (di != 0) {
      sum += b[i] - di;
    }
  }

  cout << sum << endl;
}
