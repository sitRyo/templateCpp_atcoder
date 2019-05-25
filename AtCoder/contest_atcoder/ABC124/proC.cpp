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

int main() {
  string s;
  cin >> s;

  if (s.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  string s1 = "", s2 = "";
  char z = '0', b = '1';
  bool flag = true;
  for (int i = 0; i < s.size(); ++i) {
    if (flag) {
      s1 += z;
      s2 += b;
    } else {
      s1 += b;
      s2 += z;
    }
    flag = !flag;
  }

  ll ans1 = 0, ans2 = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != s1[i]) {
      ans1 += 1;
    }
    if (s[i] != s2[i]) {
      ans2 += 1;
    }
  }

  cout << min(ans1, ans2) << endl;
}
