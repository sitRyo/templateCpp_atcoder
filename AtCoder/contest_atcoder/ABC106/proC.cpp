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
ll k;
ll b[11];

/* add your algorithm here */

int main() {
  cin >> s;
  cin >> k;

  k -= 1;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '1') {
      cout << s[i] << endl;
      return 0;
    }
    if (k == i) {
      cout << '1' << endl;
      return 0;
    }
  }
}
