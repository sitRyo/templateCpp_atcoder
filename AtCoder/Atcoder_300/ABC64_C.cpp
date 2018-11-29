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

#define INF 10e10
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

using namespace std;

typedef long long ll;

int N;
int a[MAX + 1];
bool width[8];

int main() {
  scanf("%d", &N);
  REP(i,N) scanf("%d", &a[i]);

  int count = 0;
  int over = 0;

  REP(i,8) width[i] = false;

  for (int i = 0; i < N; i++) {
    int target = a[i];
    if (target < 400) {
      width[0] = true;
    } else if (target < 800) {
      width[1] = true;
    } else if (target < 1200) {
      width[2] = true;
    } else if (target < 1600) {
      width[3] = true;
    } else if (target < 2000) {
      width[4] = true;
    } else if (target < 2400) {
      width[5] = true;
    } else if (target < 2800) {
      width[6] = true;
    } else if (target < 3200) {
      width[7] = true;
    } else {
      over++;
    }
  }

  REP(i,8) {
    if (width[i]) count++;
  }

  int min = count;
  int max = count + over;
  if (min == 0) min = 1;
  cout << min << " " << max << endl;
}
