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

typedef pair<ll,ll> pl;

int main() {
  int N,C;
  cin >> N >> C;

  ll imos[30][101010];
  rep(i,N) {
    ll s,t,c;
    cin >> s >> t >> c;
    s--, c--;
    ++imos[c][s], --imos[c][t];
  }

  for (int c = 0; c < C; ++c) {
    for (int i = 1; i < 101010; ++i) {
      imos[c][i] += imos[c][i-1];
    }
  }

  for (int c = 0; c < C; ++c) {
    for (int i = 0; i < 101010; ++i) {
      if (imos[c][i]) imos[c][i] = 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < 101010; ++i) {
    int cnt = 0;
    for (int c = 0; c < C; ++c) cnt += imos[c][i];
    ans = max(ans, cnt);
  }

  cout << ans << endl;
}
