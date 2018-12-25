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
#define repr(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n;
  cin >> n;
  vector<int> t(n+1), a(n+1);
  vector<pair<int,bool> > ans(n);
  
  rep(i,n) {
    cin >> t[i+1];
  }
  rep(i,n) {
    cin >> a[i];
  }

  t[0] = -1, a[n] = -1;

  repr(i,n+1,1) {
    if (t[i] > t[i-1]) {
      ans[i-1].first = t[i];
      ans[i-1].second = true;
    } else if (t[i] == t[i-1]) {
      ans[i-1].first = t[i];
      ans[i-1].second = false;
    }
  }

  /*for (auto itr : ans) {d
    cout << itr.first << " " << itr.second << endl;
  }*/

  for (int i = n-1; i >= 0; --i) {
    if (a[i] > a[i+1]) {
      if (ans[i].second and a[i] != ans[i].first) {
        
        cout << 0 << endl;
        return 0;
      } else if (a[i] > ans[i].first) {
        
        cout << 0 << endl;
        return 0;
      }
      ans[i].first = a[i];
      ans[i].second = true;
    } else if (a[i] == a[i+1]) {
      if (!ans[i].second) {
        if (a[i] < ans[i].first) {
          ans[i].first = a[i];
        }
      }
    }
  }

  ll res = 1;
  for (auto itr : ans) {
    if (!itr.second) {
      res = (res * itr.first) % MOD;
    }
  }
  cout << res << endl;
}
