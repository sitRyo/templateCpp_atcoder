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

template <class T = long long>
class Union_Find {
  using size_type = std::size_t;
  using _Tp = T;
public:

  vector<_Tp> par;

  const _Tp operator[] (size_type child) {
    return -par[root(child)];
  }

  Union_Find(size_type n) : par(n, -1) {}
  void init(int n) {
    par.assign(n, -1);
  }

  _Tp root(size_type x) {
    if (par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(size_type x, size_type y) {
    return root(x) == root(y);
  }

  bool merge(size_type x, size_type y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  _Tp size(int x) {
    return -par[root(x)];
  }
};
 
#include <map>

int main() {
  int n, m;
  cin >> n >> m;
  Union_Find<ll> uf(n);

  rep(i, m) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    uf.merge(x, y);
  }

  map<int, int> mp;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!mp[uf.root(i)]) {
      ans += uf[i] - 1;
      mp[uf.root(i)] = 1;
    }
  }

  cout << n - ans << endl;
}
