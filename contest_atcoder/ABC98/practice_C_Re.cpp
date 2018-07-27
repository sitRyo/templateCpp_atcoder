#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for (int i=0; i<n; i++)

int n,c,ans;

int main() {
  string s;
  cin >> n >> s;
  c = 0;
  for (int i=1; i<n; i++) {
    if (s[i] == 'E') c++;
  }
  ans = c;
  for (int i=1; i<n; i++) {
    if (s[i] == 'E') c--;
    if (s[i-1] == 'W') c++;
    ans = min(ans, c);
  }
  cout << ans;
}
