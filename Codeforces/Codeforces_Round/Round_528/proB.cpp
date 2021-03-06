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
  ll n,k,mmin = 10000000000;
  cin >> n >> k;
  for (int i = 1; i < k; ++i) {
    if (n % i == 0) {
      ll t = n / i;
      ll tmp = t * k + i;
      mmin = min<ll>(mmin,tmp);
    }
  }

  cout << mmin << endl;
}
