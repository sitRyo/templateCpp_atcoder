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


template<class T> 
class UnionFind {
  using _Tp = T;
  using size_type = std::size_t;
public:
  vector<int> par;
  vector<int> rank;
  vector<_Tp> diff_weight;
 
  UnionFind(int n = 1, _Tp SUM_UNITY = 0) {
    init(n, SUM_UNITY);
  }

  const _Tp & operator[] (size_type i) {
    root(i);
    return diff_weight[i];
  }
 
  void init(int n = 1, _Tp SUM_UNITY = 0) {
    par.resize(n); rank.resize(n); diff_weight.resize(n);
    for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
  }
 
  int root(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }
 
  _Tp weight(int x) {
    root(x);
    return diff_weight[x];
  }
 
  bool issame(int x, int y) {
    return root(x) == root(y);
  }
 
  bool merge(int x, int y, _Tp w) {
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y), w = -w;
    if (rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }
 
  _Tp diff(int x, int y) {
    return weight(y) - weight(x);
  }
};


int main() {
  int n,q;
  cin >> n >> q;
  UnionFind<int> uf(n+1);

  rep(i, q) {
    int j;
    cin >> j;
    int x,y,z;
    if (j) {
      cin >> x >> y;
      if (uf.issame(x,y)) {
        cout << uf[y] - uf[x] << endl;
      } else {
        cout << "?" << endl;
      }
    } else {
      cin >> x >> y >> z;
      uf.merge(x,y,z);
    }
  }
}
