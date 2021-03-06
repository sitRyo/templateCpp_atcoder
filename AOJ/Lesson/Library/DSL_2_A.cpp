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
#include <limits.h>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

// Beet's Segment Tree Library (Thanks for Beet)
template <typename T, typename E>
struct SegmentTree {
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  int n;
  F f; // function<T(T,T)>
  G g; // function<T(T,E)>
  T d1; // template T
  E d0; // template E

  vector<T> dat;

  // constractor
  SegmentTree() {};
  /*
   * @param
   * int n_ : number of elements
   * F f : compare elements function
   * G g : ?
   * T d1: init value
   */
  SegmentTree(int n_, F f, G g, T d1, vector<T> v = vector<T>()) : 
  f(f), g(g), d1(d1) {
    init(n_);
    if (n_ == (int)v.size()) build(n_, v);
  }

  // member methods
  void init(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    dat.clear();
    dat.resize(2*n-1, d1);
  }

  void build(int n_, vector<T> v) {
    for (int i = 0; i < n_; ++i) dat[i+n-1] = v[i];
    for (int i = n-2; i >= 0; --i) dat[i] = f(dat[i*2+1], dat[i*2+2]);
  }

  void update(int k, E a) {
    k += n-1;
    dat[k] = g(dat[k], a);
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = f(dat[k*2+1], dat[k*2+2]);
    }
  }

  inline T query(int a, int b) {
    T vl = d1, vr = d1;
    for (int l = a + n, r = b + n; l < r; l >>= 1) {
      if (l & 1) vl = f(vl, dat[(l++) - 1]);
      if (r & 1) vr = f(dat[(--r)-1], vr);
    }
    return f(vl,vr);
  }
};

int main() {
  int n,q;
  cin >> n >> q;
  SegmentTree<int, int> rmq(n,
      [](int a, int b){return min(a,b);},
      [](int a, int b){return b;},
      INT_MAX);
  for (int i = 0; i < q; ++i) {
    int c,x,y;
    cin >> c >> x >> y;
    if (c) cout << rmq.query(x,y+1) << endl;
    else rmq.update(x,y);
  }
}

