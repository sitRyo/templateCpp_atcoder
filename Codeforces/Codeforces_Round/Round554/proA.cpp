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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> a(n), b(m);

  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  ll odda = 0, evena = 0;
  ll oddb = 0, evenb = 0;

  for (auto itr : a) {
    if (itr % 2 == 1) 
      odda += 1;
    else 
      evena += 1;
  }

  for (auto itr : b) {
    if (itr % 2 == 1)
      oddb += 1;
    else 
      evenb += 1;
  }
  /*
  debug(odda);
  debug(evena);
  debug(oddb);
  debug(evenb);
*/
  ll t1 = min(odda, evenb), t2 = min(evena, oddb);

  cout << t1 + t2 << endl;
}
