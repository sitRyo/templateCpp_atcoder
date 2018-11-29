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
int c;

/* add your algorithm here */

int main() {
  cin >> c;
  cin >> s;
  int lb, rb;
  lb = rb = 0;
  int mmax = 0;

  rep(i,s.size()) {
    if (s[i] == ')') {
      mmax--;
    } else {
      mmax++;
    }

    if (mmax < 0) {
      lb++;
      mmax = 0;
    }
  }

  if (mmax > 0) {
    rb = mmax;
  }

    string l,r;
  rep(i,lb) {
    l += '(';
  }

  rep(i,rb) {
    r += ')';
  }

  string ans = l + s + r;

  cout << ans << endl;
}
