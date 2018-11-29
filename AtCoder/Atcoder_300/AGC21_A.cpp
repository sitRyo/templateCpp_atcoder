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

string s;

/* add your algorithm here */

int main() {
  cin >> s;
  int n = s.size();

  int ans = 0;

  int d = s[0] - '0' - 1;
  d += 9 * (n-1);
  ans = max(ans , d);

  d = 0;
  rep(i,n) d += s[i] - '0';
  ans = max(ans, d);

  cout << ans << endl;
}
