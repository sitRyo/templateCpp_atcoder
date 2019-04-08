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
  int n, k, mmin = 123456;
  cin >> n >> k;
  map<int, int> mp;
  vector<ll> a(k);
  vector<string> str(n);
  rep(i, k) {
    cin >> a[i];
    mp[a[i]] = 1;
  }

  rep(i,n) {
    cin >> str[i];
  }

  string match = "-";
  for (auto itr : a) {
    itr -= 1;
    if (match == "-") {
      match = str[itr];
    } else if (match == "") {
      cout << "-1" << endl;
      return 0;
    } else {
      int size = match.size();
      string tmp;
      if (str[itr].size() >= size) {
        tmp = str[itr].substr(0, size - 1);
      } else {
        tmp = str[itr];
        
        match = match.substr(0, tmp.size());
        
      }

      if (tmp != match) {
        while (match.size() > 0) {
          // cout << tmp << endl;
          tmp.pop_back();
          match.pop_back();
          if (tmp == match) break;
        }
      }
    }
  }
  if (match == "") {
    cout << "-1" << endl;
    return 0;
  }
  
  mmin = match.size();

  for (int i : {0, n-1}) {
    if (mp[i]) continue;
    string tmp = str[i].substr(0, mmin - 1);
    
    while (match.size() > 0) {
      if (tmp == match) {
        tmp.pop_back();
        match.pop_back();
      } else {
        break;
      }
    }

    if (match == "") {
      cout << "-1" << endl;
      return 0;
    }
  }

  cout << match << endl;
}
