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
#define REP(i,n) for(int i=0; i<n; ++i)
#define REP_R(i,n,m) for(int i=m; i<n; ++i)
#define NMAX 50
#define MMAX 1230

int N, M;
bool graph[NMAX+1][MMAX+1];
int p[MMAX+1];
int q[MMAX+1];
bool visited[NMAX];

void dfs(int v);

int main() {
  int a,b;
  cin >> N >> M;
  REP(i,M) {
    scanf("%d %d", &a, &b);
    p[i] = a-1; q[i] = b-1;
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }

  int ans = 0;

  REP(number,M) {
    REP(i,N) visited[i] = false;

    graph[p[number]][q[number]] = graph[q[number]][p[number]] = false;

    dfs(0);

    bool judge = false;

    REP(i,N) {
      if (!visited[i]) {
        judge = true;
        break;
      }
    }

    if (judge) ans++;

    graph[p[number]][q[number]] = graph[q[number]][p[number]] = true;
  }

  cout << ans << endl;
}

void dfs(int v) {
  visited[v] = true;
  REP(i,N) {
    if (!graph[v][i]) continue;
    if (visited[i]) continue;

    dfs(i);
  }
}
