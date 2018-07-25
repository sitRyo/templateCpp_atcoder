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
#define MAX 100000

ll N = 0;
ll p=0, g=0;
char temp;
string s;
int main() {
  cin >> s;

  rep(i,s.size()) {
    if (s[i] == 'g') {
      g++;
    } else {
      p++;
    }
    N++;
  }

  ll ans = N / 2;
  ans -= p;

  cout << ans << endl;
}
