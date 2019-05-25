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

int main() {
  int n,x,y;
  cin >> n >> x >> y;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sortd(a);

  ll t1 = x, t2 = y;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) t1 += a[i];
    else t2 += a[i];
  }

  if (t1 > t2)
    cout << "Takahashi" << endl;
  else if (t2 > t1)
    cout << "Aoki" << endl;
  else
    cout << "Draw" << endl;
}
