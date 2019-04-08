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

class Union_Find {
public:
  vector<int> par;

  Union_Find(int n) : par(n, -1) {}
  void init(int n) {
    par.assign(n, -1);
  }

  int root(int x) {
    if (par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) {
    return -par[root(x)];
  }
};

int main() {
  ll n, m, ans = 0;
  cin >> n >> m;
  Union_Find uf(n);

  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i] -= 1; b[i] -= 1;
  }
  ll con = (n * (n-1)) / 2;
  vector<ll> comf;
  // comf.push_back(con);

  for (int i = m - 1; i >= 0; --i) {
    comf.push_back(con);
    if (uf.issame(a[i], b[i])) {
      continue;
    }
    ll ta = uf.size(a[i]), tb = uf.size(b[i]);
    con -= ta * tb;
    uf.merge(a[i], b[i]);
  }

  for (int i = m - 1; i >= 0; --i) {
    cout << comf[i] << endl;
  }
}
