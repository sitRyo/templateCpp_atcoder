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
#define MAX 10000

ll N;
std::vector<ll> v;

int main() {
  cin >> N;
  rep(i,N) {
    ll temp;
    scanf("%lld", &temp);
    if (!(temp % 2)) v.push_back(temp);
  }

  ll ans = 0;

  for (auto itr = v.begin(); itr != v.end(); ++itr) {
    ll tar = *itr;
    while (tar % 2 == 0) {
      tar /= 2;
      ans++;
    }
  }

  cout << ans << endl;
}
