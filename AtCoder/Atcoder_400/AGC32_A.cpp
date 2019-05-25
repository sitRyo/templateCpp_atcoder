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

template <class T>
class vector_at {
  using size_type = std::size_t;
  using _Tp = T;
  using reference = _Tp &;
  using _array = std::vector<_Tp>;

  size_type n;
public:
  _array con;
  vector_at(size_type n) : n(n) {
    con = _array(n);
  }

  vector_at() {
    con.reserve(100);
  }

  reference
  operator[] (size_type __n) {
    return this->at(__n);
  }

  reference
  at (size_type __n) {
    return con.at(__n);
  }

  void
  push_back (_Tp t) {
    con.push_back(t);
  }

  void
  pop_back () {
    con.pop_back();
  }

  void
  sort_i () {
    std::sort(con.begin(), con.end());
  }

  void
  sort_d () {
    std::sort(con.begin(), con.end(), std::greater<_Tp>());
  }

  void
  resize (size_type __n) {
    con.resize(__n);
  }
};

int main() {
  int n;
  cin >> n;

  vector<ll> b(n), ans;
  rep(i, n) cin >> b.at(i);

  for (int i = 0; i < n; ++i) {
    int pos = -1;
    for (int j = 0; j < n - i; ++j) {
      if (j + 1 == b[j]) {
        pos = j;
        // debug(j+1);
      }
    }

    if (pos == -1) {
      cout << -1 << endl;
      return 0;
    } else {
      ans.push_back(b[pos]);
      b.erase(b.begin() + pos);
    }
  }
  
  for (int i = n - 1; i >= 0; --i) 
    cout << ans[i] << endl;
}
