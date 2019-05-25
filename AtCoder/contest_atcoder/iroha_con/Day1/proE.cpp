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
#define sortd(x) sort(x.begin(), x.end(), std::greater<ll>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  vector<ll> d(b + 2);
  d[0] = 0;
  rep(i, b) {
    cin >> d[i + 1];
  }
  d[b + 1] = n + 1;
  sorti(d);
  ll ans = 0;
  for (int i = 0; i < b + 1; ++i) {
    ll dis = d[i + 1] - d[i] - 1;
    // debug(dis);
    ans += dis / a;
    
  }

  ans += b;

  cout << (n - ans) << endl;
}
