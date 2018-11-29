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

int gcd(int x, int y);

int main() {
  int a,b;
  cin >> a >> b;

  cout << gcd(a,b) << endl;
}

// x > y
int gcd(int x, int y) {
  if (y == 0) return x;
  int amari = x % y;
  return gcd(y, amari);
}
