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
  int k, n;
  cin >> n >> k;

  vector<int> a(n), p(n);
  unordered_map<int,int> mp;
  rep(i, n) {
    cin >> a[i];
    mp[a[i]] += 1;
  }

  int diff = mp.size() - k;
  for (auto&& itr : mp) {
    // debug(itr.second);
    p[itr.second] += 1;
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (diff > 0) {
      for (int j = 0; j < p[i]; ++j) {
        diff -= 1;
        ans += i;
        if (diff <= 0) break;
      }
    } else {
      break;
    }
  }
  cout << ans << endl;
}
