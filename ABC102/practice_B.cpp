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
typedef long long ll;

int N;
ll a[105];


int main() {
  ll max = -1;
  scanf("%d", &N);
  REP(i,N) scanf("%lld", &a[i]);

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (j != i && abs(a[i] - a[j]) > max) {
        max = abs(a[i] - a[j]);
      }
    }
  }

  printf("%lld\n", max);
}
