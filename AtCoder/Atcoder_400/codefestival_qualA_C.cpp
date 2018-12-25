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
  string s;
  int k;
  cin >> s;
  cin >> k;
  const int sub = 26, len = s.size();
  int remain = k, now;
  vector<int> vec(len);
  vector<char> res(len);
  rep(i,len) {
    now = s[i] - 'a';
    char ans;
    if (now == 0) {
      ans = s[i];
    } else {
      if (remain >= (sub - now)) {
        ans = 'a';
        remain -= (sub - now);
      } else {
        ans = s[i];
      }
    }
    res[i] = ans;
  }

  if (remain > 0) {
    if (res.back() == 'a') {
      int tt = remain / 26;
      remain -= tt * 26;
    }
    int tar = res.back() - 'a';
    tar = (tar + remain) % sub;
    char t = 'a' + tar;
    res[len-1] = t;
  }

  for (auto itr : res) cout << itr;
  END;
}