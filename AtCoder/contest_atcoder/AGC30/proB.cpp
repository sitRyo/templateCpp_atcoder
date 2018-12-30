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

int main() {
  int l,n; cin >> l >> n;
  vector<ll> x(n);
  ll res = 0;
  rep(i,n) {
    cin >> x[i];
    
  }

  ll tmp = 0;
  for (int i = 0; i < n; ++i) {
    int s,g,judge = 0;
    int now = x[i];
    s = i + 1; g = n - 1;
    tmp = x[i];
    // cout << "now:" << i << endl;
    while (g >= s) {
      int pl;
      if (judge % 2 == 0) {
        pl = now + l - x[g];
        now = x[g];
        g--;
      } else {
        pl = l - now + x[s];
        now = x[s];
        s++;
      }
      judge++;
      tmp += pl;
    }
    // cout << "tmp "  << tmp << endl;
    res = max(res,tmp);
  }
  tmp = 0;
  for (int i = n-1; i >= 0; --i) {
    int s,g,judge = 0;
    int now = x[i];
    s = 0; g = i - 1;
    tmp = l - x[i];
    // cout << "now" << " " << i << endl;
    while (g >= s) {
      int pl;
      if (judge % 2 == 0) {
        pl = x[s] + l - now;
        now = x[s];
        s++;
      } else {
        pl = now + l - x[g];
        now = x[g];
        g--;
      }
      judge++;
      tmp += pl;
      // cout << tmp << endl;
    }
    
    res = max(res,tmp);
  }
  cout << res << endl;
}
