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
#define MAX 10000

int N;
int a[MAX];
int ans = 0;

int main() {
  scanf("%d", &N);
  REP(i,N) scanf("%d", &a[i]);

  int i = 1;

  while (i < N) {
    int count = 1;
    while (a[i] == a[i-1]) {
      count++;
      i++;
    }

    if (count > 1) {
      ans += count / 2;
      i--;
    }

    i++;

  }

  cout << ans << endl;
}
