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
  int n,t;
  cin >> n >> t;

  std::vector<pair<int,int> > v;

  rep(i,n) {
    int a,b;
    cin >> a >> b;
    v.pb(make_pair(b,a));
  }

  sorti(v);

  int ans = 1001;
  for (auto itr : v) {
    if (itr.first <= t) {
      ans = min(ans, itr.second);
    } else {
      if (ans == 1001) {
        cout << "TLE" << endl;
        return 0;
      }
    }
  }

  cout << ans << endl;
}
