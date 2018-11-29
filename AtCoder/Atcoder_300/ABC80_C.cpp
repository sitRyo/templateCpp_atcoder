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
#define TIME 10

int N;
bool F[MAX+1][10];
int P[MAX+1][11];
int daymax[10];
ll ans = -(1 << 30);


void dfs(int pos);
void func();

int a[10];

int main() {

  /* IO */
  scanf("%d", &N);
  REP(i,N){
    REP(j,10){
      scanf("%d", &F[i][j]);
    }
  }
  REP(i,N){
    REP(j,11){
       scanf("%d", &P[i][j]);
     }
   }
  /* ... */


  dfs(0);

  cout << ans << endl;
}

void dfs(int pos) {
  if (pos == 10) {
    func();
    return;
  }

  a[pos] = 0; dfs(pos+1);
  a[pos] = 1; dfs(pos+1);
}

void func() {
  int score = 0;
  bool all = true;

  REP(i,10) {
    if (a[i]) all = false;
  }

  if (all) return;

  REP(i,N) {
    int cc = 0;
    REP(j,10) {
      if (a[j]==1 && F[i][j]==1) ++cc;
    }
    // printf("P[%d][%d]: %d\n", i,cc,P[i][cc]);
    score += P[i][cc];
  }

  REP(i,10) {
    // printf("%d", a[i]);
  }

  // printf(" ans: %d\n", score);


  ans = (score > ans) ? score : ans;
}
