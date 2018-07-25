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
#define rep(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

int N;
ll Y;

int main() {
  cin >> N >> Y;
  int flag = false;
  int x,y,z;

  // i: 10000, j: 5000, k: 1000
  for (int i = 0; i <= N; i++) {
    x = i;
    for (int j = 0; j <= N - i; j++) {
      int k = (N - i) - j;
      ll tt = i * 10000 + j * 5000 + k * 1000;
      if (tt == Y) {
        flag = true;
        y = j; z = k;
        break;
      }
    }

    if (flag) {
      printf("%d %d %d\n", x,y,z);
      return 0;
    }
  }

  cout << "-1 -1 -1" << endl;
}
