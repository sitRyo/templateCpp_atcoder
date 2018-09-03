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
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

typedef struct complex {
  int r,i;
} complex;

complex z1, z2;

/* add your algorithm here */

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  int x3,y3,x4,y4;
  int x, y;

  x = c - a, y = d - b;

  x3 = c + b - d;
  y3 = d - a + c;
  x4 = a + b - d;
  y4 = b - a + c;

  printf("%d %d %d %d\n", x3, y3, x4, y4);
}
