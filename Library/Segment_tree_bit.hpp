#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// cut here
// (i)  iが与えられると A1 + A2 + ... + Ai を求める
// (ii) iとxが与えられたとき Ai += x
template<class T>
class SegmentTreeBIT {
  int n_; // 要素数
  vector<T> bit;
public:
  SegmentTreeBIT(int n): n_(n) {
    bit.resize(n_, 0);
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

  // Ai += x
  void add(int i, int x) {
    while (i <= n_) {
      bit[i] += x;
      i += i & -i;
    }
  }
};

// cut end;