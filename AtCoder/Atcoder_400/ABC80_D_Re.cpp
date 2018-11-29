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
  int n,C; cin >> n >> C;
  int s[n], t[n], c[n];

  int tt[200002];

  rep(i,n) {
    scanf("%d %d %d", &s[i], &t[i], &c[i]);
  }
  int sm[200002];
  rep(i,200002) sm[i] = 0;
  for (int i = 1; i <= C; ++i) {
    rep(j,200002) tt[j] = 0;
    rep(j,n) {
      if (c[j] == i) tt[s[j] * 2 - 1]++, tt[t[j] * 2]--;
    }
    for (int j = 1; j <= 200001; ++j) tt[j] += tt[j-1];
    rep(j,200002) if(tt[j] > 0) sm[j]++;
  }
  int ans = 0;
  rep(i,200002) ans = max(ans,sm[i]);
  cout << ans << endl;
}
