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
  int n; cin >> n;
  string s; cin >> s;

  ll scnt = 0, gcnt = 0;
  for (auto itr : s) {
    if (itr == 'G') gcnt++;
    else scnt++;
  }

  if (n == scnt) {
    cout << 0 << endl;
    return 0;
  } else if (n == gcnt) {
    cout << gcnt << endl;
    return 0;
  }

  ll cnt = 0;
  bool isIdeal = false;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      cnt++;
    } else {
      cnt++;
      if (s[i-1] == 'G' and cnt == gcnt) {
        isIdeal = true;
      } else if (s[i-1] == 'S' and cnt == scnt) {
        isIdeal = true;
      }
      break;
    }
  }

  if (isIdeal) {
    cout << gcnt << endl;
    return 0;
  }

  vector<ll> block;
  cnt = 0;
  ll mmax = 0, kioku = 0;
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    if (i == n-1) {
      if (s[i] == 'S') {
        if (flag) {
          mmax = max(mmax, cnt);
          flag = false;
          i = kioku;
        } else {
          mmax = max(mmax, cnt+1);
        }
      } else {
        mmax = max(mmax, cnt+1);
      }
      break;
    }
    if (s[i] == 'S' and flag) {
      mmax = max(mmax, cnt);
      cnt = 0;
      flag = false;
      i = kioku;
    } else {
      cnt++;
      if (s[i] == 'S'){
        flag = true;
        kioku = i;
      }
    }
  }
  cout << mmax << endl;
}
