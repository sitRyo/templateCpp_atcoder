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
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n;
  cin >> n;
  vector<ll> data;
  map<int, bool> checka, checkb;
  vector<pair<ll, int> > va, vb;

  for (int i = 1; i <= n; ++i) {
    ll a,b;
    scanf("%lld %lld", &a, &b);
    data.pb(a), data.pb(b);
    checka[a] = true, checkb[b] = true;
    va.pb(make_pair(a,i)), vb.pb(make_pair(b,i));
  }

  sorti(data), sorti(va), sorti(vb);

  ll res = 0;
  for (int i = 0; i < 2 * n; ++i) {
    ll target = data[i];
    if (checka[target]) {
      
      for (int j = n-1; j >= 0; --j) {
        if (vb[j].second == va[target].second) continue;

        res += min(vb[j].first, va[target].first)
      }
    } else if (checkb[i]){

    } else {
      continue;
    }
  }
}
