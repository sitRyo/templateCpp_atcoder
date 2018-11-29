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

ll n,m;
typedef pair<ll, ll> lp;

/* add your algorithm here */

int main() {
  cin >> n >> m;
  map<ll, ll> mp;
  vector<lp> de;
  rep(i,m) {
    lp p;
    cin >> p.first >> p.second;
    if (p.first == 1) mp[p.second] = p.first;
    if (p.second == n) de.pb(p);
  }

  bool flag = false;
  for (auto itr : de) {
    if (mp[itr.first] == 1) {
      flag = true;
      break;
    }
  }

  if (flag) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
