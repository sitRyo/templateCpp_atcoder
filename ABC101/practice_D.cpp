#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

#define REP(i,n) for (int i=0; i<n; i++)

using namespace std;


int func(int x) {
  int ans = 0;
  while (x>0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int main() {
  int k;
  scanf("%d", &k);
  int

  int ks = func(k);

}
