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
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  ll n,k; cin >> n >> k;
  vector<ll> h(n);
  cin >> h[0];
  ll tmp = h[0];

  for (int i = 1; i < n; ++i) {
    cin >> h[i];
    // h[i] = abs(tmp - h[i]);
  }

  sorti(h);
  ll res = h.back() - h.front() + 1;


  for (int i = 0; i <= n - k; ++i) {
    ll tmp = h[i+k-1] - h[i];
    
    if (tmp < res) res = tmp;
  }

  cout << res << endl;
}
