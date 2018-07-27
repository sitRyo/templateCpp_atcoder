#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  int ans = 0;

  int a[n];
  for (int i=0; i<n; i++) scanf("%d", &a[i]);

  if ((n-1) % (k-1) > 0) {
    ans += (n-1) / (k-1) + 1;
  } else {
    ans += (n-1) / (k-1);
  }

  cout << ans << endl;
}
