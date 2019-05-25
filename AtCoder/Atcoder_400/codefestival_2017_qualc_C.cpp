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
#include <unordered_map>
#include <set>
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

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int l = 0, r = n - 1, ans = 0;
  while (l < r) {
    if (s[l] == s[r]) {
      l += 1, r -= 1;
    } else if (s[l] != 'x' and s[r] == 'x') {
      r -= 1;
      ans += 1;
    } else if (s[l] == 'x' and s[r] != 'x')  {
      l += 1;
      ans += 1;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
