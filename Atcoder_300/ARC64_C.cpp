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

ll N,x;
std::vector<ll> a,b;
ll ans = 0;

int main() {
  cin >> N >> x;
  rep(i,N) {
    ll t1;
    scanf("%lld", &t1);
    a.push_back(t1);
  }

  for (auto itr = a.begin(); itr != a.end() - 1; ++itr) {
    ll temp = *itr + *(itr+1);
    if (temp > x) {
      ll t = temp - x;
      ans += t;
      if (*(itr + 1) > t) {
        *(itr + 1) -= t;
      } else {
        *(itr + 1) = 0;
      }
    }
  }

  cout << ans << endl;
}
