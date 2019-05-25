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

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  ll a,b,c;
  cin >> a >> b >> c;

  ll start = -1;
  ll sum = 0;
  while (true) {
    sum += a;
    ll tmp = -1;
    if (start == -1) {
      start = sum % b;
      if (start == c) {
        cout << "YES" << endl;
        return 0;
      }
      continue;
    } else {
      tmp = sum % b;
    }
    if (tmp == c) {
      cout << "YES" << endl;
      return 0;
    }

    if (tmp == start) {
      break;
    }
  }

  cout << "NO" << endl;
}
