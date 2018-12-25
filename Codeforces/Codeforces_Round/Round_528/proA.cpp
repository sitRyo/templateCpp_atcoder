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
  vector<int> a;

  if (s.size() == 1) {
    cout << s << endl;
    return 0;
  }
  if (s.size() == 2) {
    cout << s << endl;
    return 0;
  }

  int half;
  if (s.size() % 2 == 1) {
    half = s.size() / 2;
  } else {
    half = s.size() / 2;
    half -= 1;
  }
  rep(i,s.size()) {
    if (i % 2 == 0) {
      a.pb(half - i);
      half -= i;
    } else {
      a.pb(half + i);
      half += i;
    }
  }

  for (auto itr : a) {
    cout << s[itr];
  } END;
}
