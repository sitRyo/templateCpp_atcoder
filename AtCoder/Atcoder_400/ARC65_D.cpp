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
#include <map>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))

struct union_find_tree {
    vector<int> data;
    union_find_tree() = default;
    explicit union_find_tree(size_t n) : data(n, -1) {}
    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }
    int tree_size(int i) { return - data[find_root(i)]; }
    int unite_trees(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (tree_size(i) < tree_size(j)) swap(i,j);
            data[i] += data[j];
            data[j] = i;
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
};

int main() {
    int n, k, l; cin >> n >> k >> l;
    union_find_tree uft1(n);
    REP (i, k) {
        int p, q; cin >> p >> q; -- p; -- q;
        uft1.unite_trees(p, q);
    }
    union_find_tree uft2(n);
    REP (i, l) {
        int r, s; cin >> r >> s; -- r; -- s;
        uft2.unite_trees(r, s);
    }
    map<pair<int, int>, int> cnt;
    REP (i, n) {
        cnt[make_pair(uft1.find_root(i), uft2.find_root(i))] += 1;
    }
    REP (i, n) {
        cout << cnt[make_pair(uft1.find_root(i), uft2.find_root(i))] << ' ';
    }
    cout << endl;
    return 0;
}
