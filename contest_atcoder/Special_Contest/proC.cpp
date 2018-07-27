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

double ans;
ll n, m, d, a;

int main() {
  cin >> n >> m >> d;
  m = m - 1;
  ans = m / n;
  if (d == 0) d = 1;
  ans = ans * d;
  cout << d << endl;
}
