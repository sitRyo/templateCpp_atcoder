#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// cut here
// (i)  iが与えられると A1 + A2 + ... + Ai を求める
// (ii) iとxが与えられたとき Ai += x
// 1-indexに注意！
template<class T>
class SegmentTreeBIT {
  int n_; // 要素数
  vector<T> bit;
public:
  SegmentTreeBIT(int n): n_(n) {
    bit = vector<long long>(100000,0);
  }

  // A1 + ... + Aiまでの和
  T sum(int i) {
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  // Ai += x(i -> 変更するインデックス, x -> 加算する値)
  void add(int i, T x) {
    while (i <= n_) {
      bit[i] += x;
      i += i & -i;
    }
  }

  void showTree() {
    for (auto itr : bit) {
      cout << itr << " ";
    }
    cout << endl;
  }
};

// cut end;

void solve(int n, vector<long long> &a, SegmentTreeBIT<long long> &bit);

int main() {
  int n;
  cin >> n;
  SegmentTreeBIT<long long> bit(n);
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  solve(n, a, bit);
}

void solve(int n, vector<long long> &a, SegmentTreeBIT<long long> &bit) {
  long long ans = 0;
  for (int j = 0; j < n; ++j) {
    ans += j - bit.sum(a[j]);
    bit.add(j+1,a[j]);
  }

  printf("%lld\n", ans);
}