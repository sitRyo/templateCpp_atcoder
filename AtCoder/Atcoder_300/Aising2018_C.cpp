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

ll hans = 0, wans = 0;
int h, w;
vector<string> s;
vector<vector<bool>> check;

using pi = pair<int,int>;

void dfs(int nh, int nw, char t, pi cnt) {
  if (t == '#') cnt.first += 1;
  else cnt.second += 1;

  for (int i = -1; i <= 1; i += 2) {
    for (int j = -1; j <= 1; j += 2) {
      int th = nh + i, tw = nw + j;
      if (th >= 0 and th < h and tw >= 0 and tw < w and !check[th][tw]) {
        if (t == '#') {
          if (s[th][tw] == '.') {
            dfs(th, tw, s[th][tw], cnt);
          }
        } else {
          if (s[th][tw] == '#') {
            dfs(th, tw, s[th][tw], cnt);
          }
        }
      }
    }
  }
}


int main() {
  cin >> h >> w;

  rep(i, h) {
    cin >> s[i];
  }
  ll ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (!check[i][j]) {
        pi p;
        dfs(i, j, s[i][j], p);
        ans += p.first * p.second;
      }
    }
  }

  cout << ans << endl;
}
