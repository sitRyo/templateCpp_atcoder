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
#include <map>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll n;

/* add your algorithm here */

int main() {
  cin >> n;
  vector<string> v;
  string s;
  bool flag = false;
  rep(i,n) {
    cin >> s;
    v.pb(s);
  }

  rep(i,n) {
    rep(j,n) {
      if (i == j) continue;
      if (v[i] == v[j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    string a = v[i-1], b = v[i];
    if (a.back() != b[0]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
