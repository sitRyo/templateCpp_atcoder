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
  ll cnt = 0;
  string t = "keyence";
  for (int i = 0; i < 7; ++i) {
    if (s[i] == t[i]) {
      cnt++;
    } else {
      break;
    }
  }

  int j = 6;
  for (int i = s.size() - 1; i >= s.size() - 8; --i) {
    if (s[i] == t[j]) {
      j--;
      cnt++;
    } else {
      break;
    }
  }

  if (cnt >= 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
