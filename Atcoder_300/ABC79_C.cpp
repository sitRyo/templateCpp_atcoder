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
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

int main() {
  int s[4];
  string tar;
  cin >> tar;

  REP(i,4) {
    s[i] = tar[i] - '0';
  }

  for (int i = 0; i < 8; ++i) {
    int sum = s[0];
    string ope;
    bool flag[3];
    REP(loop,3) flag[loop] = false;

    int bin = i, count = 0;
    while (bin > 0) {

      if (bin % 2) {
        flag[count] = true;
      }

      bin /= 2;
      count++;

    }

    for (int j = 0; j < 3; ++j) {
      if (flag[j]) {
        sum += s[j+1];
        ope += '+';
      } else {
        sum -= s[j+1];
        ope += '-';
      }
    }

    if (sum == 7) {
      printf("%d%c%d%c%d%c%d=7\n", s[0], ope[0], s[1], ope[1], s[2], ope[2], s[3]);
      return 0;
    }
  }
}
