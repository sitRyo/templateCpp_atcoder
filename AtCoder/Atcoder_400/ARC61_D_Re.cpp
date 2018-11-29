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

typedef pair<ll,ll> pl;

int main() {
  ll h,w,n; cin >> h >> w >> n;
  map<pl, int> grid;
  rep(i,n) {
    ll a,b; cin >> a >> b;

    rep(j,3)rep(k,3) {
      int dj = a - j,dk = b - k;
      if (dj > 0)
    }
  }
}
