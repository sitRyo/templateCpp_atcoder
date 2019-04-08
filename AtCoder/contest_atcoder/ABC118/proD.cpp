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

string f(char x, int start, int end) {
  string s;
  for (int i = 1; i < start; ++i) {
    s.push_back(0);
  }
  for (int i = 0; i < end; ++i) {
    s.push_back(x);
  }
  return s;
}

int main() {
  string ans = "";
  int n,m;
  cin >> n >> m;
  vector<int> a(m), elements(10);
  map<int,int> mp,sub;
  
  elements[1] = 2;
  elements[2] = 5;
  elements[3] = 5;
  elements[4] = 4;
  elements[5] = 5;
  elements[6] = 6;
  elements[7] = 3;
  elements[8] = 7;
  elements[9] = 6;
  rep(i,m) {
    cin >> a[i];
    mp[elements[a[i]]] = a[i];
  }

  // 残っているマッチで作れる数の最大値はいくつか？
  rep(i,m) {
    ll tmp = a[i], mac = elements[a[i]], digit = 1;
    sub[a[i]] = elements[a[i]];
    rep(j,m) {
      if (i != j) {
        digit *= 10;
        tmp += a[j] * digit;
        mac += elements[a[j]];
        if (sub[mac] == 0) {
          sub[mac] = tmp;
        } else if (sub[mac] != 0 and sub[mac] < tmp) {
          sub[mac] = tmp;
        }
      }
    }
  }

  for (auto itr : a) {
    int remain = n;
    int mac = elements[itr];

    string s = "";

    while (remain > 0) {
      remain -= mac;
      if (remain >= 0) {
        s += itr + '0';
      } else {
        remain += mac;
        break;
      }
    }
    cout << s << endl;
    string tr = "";
    bool flag = false;
    while (s.size()) {
      if (sub[remain] != 0) {
        int tar = sub[remain];
        while (tar > 0) {
          int tt = tar % 10;
          tar /= 10;
          tr.push_back(tt + '0');
        }
        flag = true;
        break;
      }
      s.pop_back();
      remain += mac;
    }
    
    if (flag) {
      if (tr.back() > s.back()) {
        rep(i,tr.size()) {
          s.push_back(tr[i]);
        }
      }
      s = tr + s;
    }

    string tmpans = "";
    for (int i = s.size()-1; i >= 0; --i) {
      tmpans.push_back(s[i]);
    }

    if (ans.size() < tmpans.size()) {
      ans = tmpans;
    } else {
      for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] > tmpans[i]) {
          break;
        } else if (ans[i] < tmpans[i]) {
          ans = tmpans;
          break;
        }
      }
    }
  }

  cout << ans << endl;
}
