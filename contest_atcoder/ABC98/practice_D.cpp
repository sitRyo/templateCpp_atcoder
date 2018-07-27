#include <cstdio>
#include <cmath>

#define REP(i,n) for (int i=0; i<n; i++)

int n;
long A[1<<20];
long total[1<<20];
long score = 0;
long ans = 0;

int main() {
  scanf("%d", &n);
  REP(i,n) scanf("%ld", &A[i]);


  REP(i,n) {
    int tt=0;
    int sum=0;
    for (int j=i; j<n; j++) {
      tt ^= A[j];
      sum += A[j];
      if (tt == sum) ans++;
    }
  }
  printf("%ld",ans);
}
