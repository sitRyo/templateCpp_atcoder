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
  int r,c;
  cin >> r >> c;
  vector<string> C(r);
  rep(i,r){
    string str;
    char ch;
    rep(j,c) {
      cin >> ch;
      str.push_back(ch);
    }
    C[i] = str;
  }

  int ans = 0, tmp = 0;
  rep(i,r) {
    if (i % 2 == 0) {
      rep(j,c) {
        if (j % 2 == 0 and C[i][j] == '.') ans += 1;
      }
    } else {
      rep(j,r) {
        if (j % 2 == 1 and C[i][j] == '.') ans += 1;
      }
    }
  }

  rep(i,r) {
    if (i % 2 == 0) {
      rep(j,c) {
        if (j % 2 == 1 and C[i][j] == '.') tmp += 1;
      }
    } else {
      rep(j,r) {
        if (j % 2 == 0 and C[i][j] == '.') tmp += 1;
      }
    }
  }

  cout << max(ans,tmp) << endl;
}
