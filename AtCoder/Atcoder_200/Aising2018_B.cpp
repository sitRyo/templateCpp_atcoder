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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  int a,b,n;
  cin >> n >> a >> b;

  vector<ll> p(n);
  rep(i, n) cin >> p[i];

  sorti(p);

  ll ans[3] = {0,0,0};
  for (int i = 0; i < n; ++i) {
    if (p[i] <= a) {
      ans[0] += 1;
    } else if (p[i] >= a+1 and p[i] <= b) {
      ans[1] += 1;
    } else {
      ans[2] += 1;
    }
  }

  cout << min({ans[0], ans[1], ans[2]}) << endl;
}
