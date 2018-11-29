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
#define MAX 100
#define MOD 1000000007
#define pb push_back

int main() {
  ll n,m;
  cin >> n >> m;

  vector<int> num(n+1,1);
  vector<bool> red(n+1,0);

  red[1] = true;

  ll x, y;
  rep(i,m) {
    cin >> x >> y;
    if (red[x]) red[y] = true;
    num[x] = num[x] - 1, num[y] = num[y] + 1;
    if (num[x] == 0) red[x] = false;
  }

  ll ans = 0;
  rep(i,n+1) {
    if (red[i]) ans++;
  }

  cout << ans << endl;
}
