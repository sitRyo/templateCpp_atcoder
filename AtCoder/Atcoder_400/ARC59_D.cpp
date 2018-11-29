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
  cin >> s;
  ll len = s.size();

  bool flag = false;
  ll start, end;
  for (int i = 0; i < len-1; ++i) {
    if (s[i] == s[i+1]) {
      flag = true;
      start = i + 1, end = i + 2;
      break;
    }
  }

  for (int i = 0; i < len - 2; ++i) {
    if (s[i] == s[i+2]) {
      flag = true;
      start = i + 1; end = i + 3;
      break;
    }
  }

  if (flag) {
    cout << start << " " << end << endl;
  } else {
    printf("-1 -1\n");
  }
}
