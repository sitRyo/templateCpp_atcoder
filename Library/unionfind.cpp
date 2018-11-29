#include <vector>
using namespace std;

/* Union-Find-Tree */
/* 必ず要素数をコンストラクタに入れること */
class Union_Find {
public:
  vector<long long> par;
  vector<long long> rnk;

  Union_Find (long long n) {
    par.resize(n), rnk.resize(n);
    for (int i = 0; i < n; ++i) {
      par[i] = i;
      rnk[i] = 0;
    }
  }

  // 木の根を求める
  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

  // xとyの属する集合を併合
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rnk[x] < rnk[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rnk[x] == rnk[y]) rnk[x]++;
    }
  }

  // xとyが同じ集合に属するか否か
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};
