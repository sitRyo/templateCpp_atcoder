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
#include <stack>
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
  stack<char> stc;

  for (auto itr : s) {
    if (itr != 'B') {
      stc.push(itr);
    } else {
      if (stc.size() > 0) {
        stc.pop();
      } else {
        ;
      }
    }
  }

  vector<char> c;
  while (stc.size() > 0) {
    char tmp = stc.top();
    stc.pop();
    c.pb(tmp);
  }

  for (int i = c.size() - 1; i >= 0; --i) {
    cout << c[i];
  }
  END;
}
