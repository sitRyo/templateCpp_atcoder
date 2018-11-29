#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define REP(i,n) for (int i=0; i<n; i++)
typedef long long ll;

int main() {
  ll a[10001];
  ll b[10001];
  int n;
  int ans = 0;
  bool flag = true;
  int c4 = 0, c2 = 0;

  scanf("%d", &n);
  REP(i,n) scanf("%lld", &a[i]);

  REP(i,n){
    if (a[i] % 2 == 0){
      b[c2] = a[i];
      c2++;
    }
  }
  int count = 0;
  REP(i,c2) {
    b[i] *= count;
    while (!(b[i]%2)) {
      ans++; count++;
    }
  }
  printf("%d\n", ans);
}
