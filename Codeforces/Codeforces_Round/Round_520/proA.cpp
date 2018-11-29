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
  int n; scanf("%d", &n);
  vector<int> a(n);

  rep(i,n) scanf("%d", &a[i]);
  int first = a.front(), end = a.back();
  int ans = 0;

  
  for (int i = 0; i < n; ++i) {
    if (a[i] == i+1) {
      ans = i;
    } else {
      break;
    }
  }

  int tho = 1000, tt = 0, tmp = 0;
  for (int i = n-1; i >= 0; --i) {
    if (a[i] == tho) {
      tmp = tt;
      tt++;
      tho--;
    } else {
      break;
    }
  }
  ans = max(ans,tmp);

  tmp = 0;
  for (int i = n-1; i >= 0; --i) {
    if (a[i] - a[i-1] == 1) {
      tmp++;
    } else {
      break;
    }
  }

  ans = max(ans,tmp-1);

  tmp = 0;
  for (int i = 0; i < n-1; ++i) {
    if (abs(a[i] - a[i+1]) == 1) {
      tmp++;
    } else {
      ans = max(tmp-1, ans);
      tmp = 0;
    }
  }
  cout << ans << endl;
}
