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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

typedef pair<ll,ll> pL;
const int MAX = 210000;

ll fac[MAX], finv[MAX], inv[MAX];

pL prime_factorize(ll n) {
  vector<pL> res;
  for (ll p = 2; p * p <= n; ++p) {
    if (n % p != 0) continue;
    int num = 0;
    while (n % p == 0) {
      ++num;
      n /= p;
    }
    res.pb(make_pair(p, num));
  }
  if (n != 1) res.pb(make_pair(n,1));
}


