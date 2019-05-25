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
  int n, m;
  cin >> n >> m;
  
  vector<bool> judge(n, false);
  vector<ll> x(m), y(m), cnt(n, 1);

  judge[0] = true;

  rep(i,m) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
  }

  for (int i = 0; i < m; ++i) {
    ll before = x[i], after = y[i];
    if (cnt[before] == 1) {
      if (judge[before]) {
        judge[before] = false;
        judge[after] = true;
      }
    } else if (cnt[before] > 1) {
      if (judge[before]) {
        judge[after] = true;
      }
    }
    cnt[before] -= 1;
    cnt[after] += 1;
  }

  auto ans = [](vector<bool> j) {
    ll c = 0;
    for (auto itr : j) {
      c += (itr) ? 1 : 0;
    }

    return c;
  };

  cout << ans(judge) << endl;
}
