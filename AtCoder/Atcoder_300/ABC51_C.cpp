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

typedef pair<int, int> P;

int sx, sy, tx, ty;
char dir[4] = {'U', 'D', 'L', 'R'};
bool flag = true;

int main() {
  scanf("%d %d %d %d", &sx, &sy, &tx, &ty);

  int dx, dy;
  dx = tx - sx; dy = ty - sy;
  int count = 0;

  while(count < 2) {
    for (int i = 0; i < dx; i++) {
      if (count == 0) {
        printf("R");
      } else {
        printf("L");
      }
    }
    for (int i = 0; i < dy; i++) {
      if (count == 0) {
        printf("U");
      } else {
        printf("D");
      }
    }
    count++;
  }

  count = 0;
  dx++; dy++;

  while (count < 2) {

    if (count == 0) {
      printf("D");
    } else {
      printf("U");
    }

    for (int i = 0; i < dx; i++) {
      if (count == 0) {
        printf("R");
      } else {
        printf("L");
      }
    }

    for (int i = 0; i < dy; i++) {
      if (count == 0) {
        printf("U");
      } else {
        printf("D");
      }
    }

    if (count == 0) {
      printf("L");
    } else {
      printf("R");
    }

    count++;
  }

  cout << endl;
}
