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
#define MAX 50

using namespace std;

int h,w;
char grid[MAX + 5][MAX + 5];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool flag = false;
int cnt = 0;

int main() {
  memset(grid, '.', sizeof(grid));
  cin >> h >> w;
  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {
      if (grid[i][j] == '#') {
        if (grid[i-1][j] == '.' && grid[i][j-1] == '.' && grid[i+1][j] == '.' && grid[i][j+1] == '.') {
          printf("No\n");
          return 0;
        }
      }
    }
  }

  printf("Yes\n");

  return 0;
}
