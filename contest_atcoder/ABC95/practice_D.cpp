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

#define INF 1000000000
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX_N 100000
#define MAX_C 100000000000000
#define MAX_V 1000000000

using namespace std;

int N,C;
int x[MAX_C+5];
int v[MAX_V+5];
int ans = 0;

int main() {
  scanf("%d %d", &N, &C);
  x[0] = 0; v[0] = 0;
  REP(i,N) scanf("%d %d", &x[i+1], &v[i+1]);

  int i = 0, j, left, right, dis;
  while (i <= N) {
    j = (i-1 < 0) ? N-1 : i-1;
    left = (x[j] > x[i+1]) ? C - x[j] : x[j];
    right = (x[i+1] < x[j]) ? C + x[i+1] : x[i+1];
    dis = (abs(x[i] - left) < abs(x[i] - right)) ? abs(x[i] - left) : abs(x[i] - right);
    if (dis > v[])
  }
}
