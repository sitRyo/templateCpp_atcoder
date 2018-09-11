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

int n;

/* add your algorithm here */

int main() {
  cin >> n;
  vector<int> s(n,0);
  int sum = 0;
  rep(i,n) {
    cin >> s[i];
    sum += s[i];
  }

  if (sum % 10 != 0) {
    cout << sum << endl;
  } else {
    int t = 101;
    for (auto itr : s) {
      if (itr % 10 != 0) {
        t = min(t,itr);
      }
    }
    if (t == 101) sum = 0;
    else sum -= t;
    cout << sum << endl;
  }
}
