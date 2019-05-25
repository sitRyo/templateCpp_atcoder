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
  int n, m;
  cin >> n;

  map<string, pair<int,int>> mp;
  string s;
  rep(i, n) {
    cin >> s;
    mp[s].first += 1;
  }

  cin >> m;
  rep(i, m) {
    cin >> s;
    mp[s].second += 1;
  }

  int mmax = 0;
  for (auto&& itr : mp) {
    pair<int,int> p = itr.second;
    mmax = max(p.first - p.second, mmax);
  }
  cout << mmax << endl;
}
