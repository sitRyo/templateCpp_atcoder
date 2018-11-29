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
#include <map>
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

/*

考察
駅a,b,cが同じ根を持つか？

 */

int main() {
  int n,m;
  cin >> n >> m;

  vector<vector<int> > E(n);

  rep(i,m) {
    ll a,b,l;
    scanf("%lld %lld %lld", &a, &b, &l);
    a--, b--;
    E[a].pb(l);
    E[b].pb(l);
  }

  int ans = 0;
  rep(i,n) {
    map<int,int> m;
    rep(j, E[i].size()) {
      ans += m[2540 - E[i][j]];
      m[E[i][j]]++;
    }
  }

  cout << ans << endl;
}

