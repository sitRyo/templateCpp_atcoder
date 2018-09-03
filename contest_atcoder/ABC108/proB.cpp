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

int xa, ya, xb, yb;

/* add your algorithm here */

int main() {
  cin >> xa >> ya >> xb >> yb;

  int xd ,yd;
  xd = abs(xa - xb);
  yd = abs(ya - yb);

  int xc= xb + yd;
  int yc= yb + xd;
  int xdd= xa + yd;
  int ydd= ya + xd;

  if (xb >= xa && yb >= ya) {
    xc = xb - yd;
    yc = yb + xd;
    xdd = xa - yd;
    ydd = ya + xd;
  } else if (xa >= xb && yb >= ya) {
    xc = xb - yd;
    yc = yb - xd;
    xdd = xa - yd;
    ydd = ya - xd;
  } else if (xb >= xa && ya >= yb){
    xc = xb + yd;
    yc = yb + xd;
    xdd = xa + yd;
    ydd = ya + xd;
  } else {
    xc = xb + yd;
    yc = yb - xd;
    xdd = xa + yd;
    ydd = ya - xd;
  }

  cout << xc << " " << yc << " " << xdd << " " << ydd << endl;
}
