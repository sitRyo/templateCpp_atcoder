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

int main() {
  int n;
  cin >> n;
  vector<int> b(n), one;
  map<int,int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (i == 0 or (b[i] == 1 and b[i-1] != 1)) {
      one.push_back(i);
    }
  }

  int pre = n;
  vector<int> ans;
  for (int i = 0; i < one.size(); ++i) {
    int last = one.size() - 1 - i;
    int pos = one[last];
    map<int,int> mp;
    for (int j = pos; j < pre; ++j) {
      mp[b[j]] += 1;
    }
 
    pre = pos;
    for (auto itr : mp) {
      for (int k = 0; k < itr.second; ++k) {
        ans.push_back(itr.first);
      }
    }
  }

  vector<int> t(n+1, 0);
  int tim = 0;
  for (auto itr : ans) {
    int ta = itr - 1;
    cout << itr << endl;
    tim += 1;
    
    if (itr > tim) {
      cout << -1 << endl;
      return 0;
    }
    pre = t[ta];
    int now;
    for (int i = itr; i < tim; ++i) {
      now = t[i];
      t[i] = pre;
      pre = now;
    }
    t[ta] = itr;
  }

  for (auto itr : t) {
    cout << itr << " ";
  }END;

  for (int i = 0; i < n; ++i) {
    // cout << t[i] << ' ' << b[i] << endl;
    if (t[i] != b[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  for (auto itr : ans) {
    cout << itr << endl;
  }
}
