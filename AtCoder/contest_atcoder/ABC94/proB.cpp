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
  int n,m,x;
  cin >> n >> m >> x;

  vector<int> v(m,0);
  int sum[n+1];
  rep(i,n+1) sum[i] = 0;
  rep(i,m) {
    cin >> v[i];
    sum[v[i]]++;
  }

  int tmp1 = 0, tmp2 = 0;
  for (int i = 1; i <= x; ++i) {
    if (sum[i] > 0) {
      tmp1++;
    }
  }

  for (int i = n; i >= x; --i) {
    if (sum[i] > 0) {
      tmp2++;
    }
  }

  cout << min(tmp1,tmp2) << endl;
}
