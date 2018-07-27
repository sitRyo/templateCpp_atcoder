#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cmath>
#include <cstdlib>

#define INF 1000000000
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

using namespace std;

long N,Q;
long x[100005];
long c[100005], d[100005];

int main() {
  scanf("%ld %ld", &N, &Q);
  REP(i,N) scanf("%ld", &x[i]);
  REP(i,Q) scanf("%ld %ld", &c[i], &d[i]);

  long left, right, count = 0;
  for (long i = 0; i < Q; i++) {
    long pos_left = 0, pos_right = 0;
    left = (c[i] - d[i] >= 0) ? c[i] - d[i] : 0;
    right = c[i] + d[i];

    printf("%d\n", right);
    if (x[N-1] < right){
      printf("%d\n", d[i] * N);
      continue;
    }

    printf("----------------\n");
    long a = 0;
    for (long j = x[a]; j <= right; j = x[++a]) {
      if (j > left && j < right) {
        if (!(pos_left)) pos_left = a;
        printf("%d\n", j);
        printf("abs: %ld\n", abs(j - c[i]));
        count += abs(j - c[i]);
        pos_right = a;
      }
    }

    printf("%ld %ld\n", pos_left, pos_right);
    count += (pos_left + (N-1-pos_right)) * d[i];
    printf("%ld\n", count);

    printf("----------------\n");
    count = 0;
  }
}
