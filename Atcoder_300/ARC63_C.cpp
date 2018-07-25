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

int main() {
  string s;
  ll ans = 0;
  cin >> s;

  for (int i = s.size()-1; i > 0; --i) {
    if (s[i] != s[i-1]) {
      ++ans;
    }
  }

  cout << ans << endl;
}
