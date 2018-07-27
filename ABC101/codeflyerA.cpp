#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>

#define INF 1000000000
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

using namespace std;

int N;
long long p[105];

int main() {
  scanf("%d", &N);
  REP(i,N) scanf("%lld", &p[i]);

  bool flag = true;
  int count = 0;
  int judge;

  while (flag) {
    REP(i,N) {
      judge = p[i] % 10;
      if (judge) flag = false;
      p[i] /= 10;
    }
    if (flag) count++;
    else break;
  }

  printf("%d\n", count);
}
