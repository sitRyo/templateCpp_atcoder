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

vector<int> v(3,0);

/* add your algorithm here */

int main() {
  rep(i,3) cin >> v[i];
  sort(v.begin(), v.end());

  int ans = v[2] * 10 + v[1] + v[0];

  cout << ans << endl;
}
