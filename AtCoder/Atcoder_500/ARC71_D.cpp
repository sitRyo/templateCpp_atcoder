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

ll sums(vector<ll> vec) {
  ll limit = vec.size();
  ll sumvec = 0;
  for (int k = 1; k <= limit; ++k) {
    sumvec += (k - 1) * vec[k-1] - (limit - k) * vec[k-1];
    sumvec %= MOD;
  }

  return (sumvec + MOD);
}

int main() {
  ll n,m;
  vector<ll> x, y;

  cin >> n >> m;

  x = vector<ll>(n), y = vector<ll>(m);

  rep(i,n) {
    scanf("%lld", &x[i]);
  }
  rep(i,m) {
    scanf("%lld", &y[i]);
  }
  
  ll sumx = sums(x);
  ll sumy = sums(y);

  cout << (sumx * sumy) % MOD << endl;
}
