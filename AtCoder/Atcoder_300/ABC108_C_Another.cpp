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

// 別解法, aを決め打つ
int main() {
  int n,k;
  cin >> n >> k;

  vector<ll> num(k,0);

  ll ans = 0;
  for (int i = 1; i <= n; ++i) num[i%k]++;

  for (int a = 0; a < k; ++a) {
    int b = (k-a) % k;
    int c = (k-a) % k;
    if ((b+c) != k) continue;
    ans += num[a] * num[b] * num[c];
  }

  cout << ans << endl;
}
