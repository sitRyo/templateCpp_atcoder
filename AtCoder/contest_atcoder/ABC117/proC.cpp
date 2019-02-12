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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> x(m);
  rep(i,m) {
    cin >> x[i];
  }

  if (n >= m) {
    cout << 0 << endl;
    return 0;
  }

  sorti(x);
  vector<ll> sum;
  for (int i = 0; i < m-1; ++i) {
    sum.push_back(x[i+1] - x[i]);
  }

  sorti(sum);
  int aa = n - 1;
  ll ans = 0;
  for (int i = 0; i < sum.size() - aa; ++i) {
    ans += sum[i];
  }

  cout << ans << endl;
}
