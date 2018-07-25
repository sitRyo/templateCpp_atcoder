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
#define MAX 3

int c[MAX][MAX];
int target = MAX+1;

bool func(int a[MAX], int b[MAX]) {
  bool flag = true;

  rep(i,MAX) {
    rep(j,MAX) {
      if (a[i] + b[j] != c[i][j]) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
  }

  return flag;
}

int main() {
  rep(i,MAX)rep(j,MAX){
    cin >> c[i][j];
  }

  int a[3],b[3];

  for (int i = 0; i <= c[0][0]; ++i) {
    a[0] = i; b[0] = c[0][0] - i;
    for (int j = 0; j <= c[1][1]; ++j) {
      a[1] = j; b[1] = c[1][1] - j;
      for (int k = 0; k <= c[2][2]; ++k) {
        a[2] = k; b[2] = c[2][2] - k;

        if (func(a,b)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
}
