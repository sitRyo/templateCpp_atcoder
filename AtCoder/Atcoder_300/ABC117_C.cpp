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
  int n, m;
  cin >> n >> m;

  vector<ll> x(m), diff;
  rep(i, m) cin >> x[i];

  if (n >= m) {
    cout << 0 << endl;
    return 0;
  }

  sorti(x);
  ll sum = 0;
  for (int i = 0; i < m - 1; ++i) {
    diff.push_back(abs(x[i+1] - x[i])); 
  }

  sorti(diff);

  for (int i = 0; i < diff.size() - (n - 1); ++i) {
    sum += diff[i];
  }

  cout << sum << endl;
}
