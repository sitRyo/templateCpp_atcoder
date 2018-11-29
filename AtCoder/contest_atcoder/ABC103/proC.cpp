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

int main() {
  int a,b,c;

  scanf("%d %d %d", &a, &b, &c);

  int ans = 0, ans1 = 0;

  ans1 = abs(a-b) + abs(b-c);
  ans = abs(a-c) + abs(c-b);
  ans1 = min(ans,ans1);
  ans = abs(b-a) + abs(a-c);
  ans1 = min(ans,ans1);
  ans = abs(b-c) + abs(c-a);
  ans1 = min(ans,ans1);
  ans = abs(c-a) + abs(a-b);
  ans1 = min(ans,ans1);
  ans = abs(c-b) + abs(b-a);

  cout << ans1 << endl;
}
