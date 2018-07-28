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
#define MAX 10e9

ll mul = 1000000007;
ll N;
std::vector<ll> v;
ll ans = 1;

int main() {
  cin >> N;
  rep(i,N) {
    ll a;
    scanf("%lld", &a);
    v.push_back(a);
  }

  ll end = N - 1;
  ll bucket[N];
  rep(i,N) bucket[i] = 0;

  sort(v.begin(), v.end());

  for (auto itr = v.begin(); itr != v.end(); ++itr) {
    bucket[*itr]++;
  }

  for (int i = end; i >= 0; i -= 2) {
    if (i == 0) {
      if (!bucket[i]) {
        cout << 0 << endl;
        return 0;
      }
    } else {
      if (!(bucket[i] == 2)) {
        cout << 0 << endl;
        return 0;
      } else {
        ans *= 2;
        ans %= mul;
      }
    }
  }

  cout << ans << endl;
}
