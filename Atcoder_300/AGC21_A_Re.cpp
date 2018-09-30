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
#define END cout << endl
#define MOD 1000000007
#define pb push_back

int main() {
  ll n;
  cin >> n;

  ll t = n, cnt = 0;
  int digit = 0, tmp = 0;
  while (t > 0) {
    if (t / 10 == 0) digit = t % 10;
    tmp += t % 10;
    t /= 10, cnt++;
  }
  int res = digit + (cnt-1) * 9;
  if (tmp != res) res--;

  cout << res << endl;
}
