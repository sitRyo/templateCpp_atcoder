// セグメント木(区間の最小値を求めるRMQ用)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

long long SEG_MAX = 2147483647;

template<typename T>
class SegmentTreeRMQ {
  int n;
  vector<T> dat;
public:
  // 数列を渡す。
  SegmentTreeRMQ(vector<T> v) {
    int size = v.size();
    n = 1;
    while (n < size) n *= 2;
    dat.resize(2 * n -1, SEG_MAX);

    for (int i = 0; i < size; ++i) dat[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = min(dat[2 * i + 1], dat[2 * i + 2]); 
  }

  T getElements() {
    return n;
  }

  void update(int x, T val) {
    x += n - 1;
    dat[x] = val;
    while (x > 0) {
      x = (x - 1) / 2;
      dat[x] = min (dat[2 * x + 1], dat[2 * x + 2]);
    }
  }

  // [a, b), k: 節点, [l,r) rはセグメント木の要素数 (n * 2 - 1);
  int find(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (r <= a or b <= l) return SEG_MAX;
    if (a <= l and r <= b) return dat[k];

    T vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
    T vr = find(a, b, 2 * k + 2, (l + r) / 2, r);

    return min(vl, vr);
  }
};

int main() {
  ll n,q;
  cin >> n >> q;

  SegmentTreeRMQ<long long> seg(vector<long long>(n, SEG_MAX));

  for (int i = 0; i < q; ++i) {
    long long c,x,y;
    cin >> c >> x >> y;
    if (c == 0) seg.update(x,y);
    else cout << seg.find(x,y+1,0,0,seg.getElements()) << endl;
  }


  // cout << ((0 < 0) ? "ok" : "ng") << endl;
}