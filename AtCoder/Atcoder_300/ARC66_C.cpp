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
#define MUL 10e9

ll mul = MUL + 7;
ll N;
std::vector<ll> data;

int main() {
  cin >> N;
  rep(i,N) {
    ll a;
    scanf("%lld", &a);
    data.push_back(a);
  }

  int bucket[N];

  rep(i,N) bucket[i] = 0;
  bool flag = false;
  for (auto itr = data.begin(); itr != data.end(); ++itr) {
    bucket[*itr]++;
    if (*itr != 0) {
      if (bucket[*itr] > 2) {
        flag = true;
      }
    } else {
      if (bucket[*itr] > 1) {
        flag = true;
      }
    }
    if (flag) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll bin = data.size() / 2;
  ll ans = 1;
  rep(i,bin) {
    ans *= 2;
  }

  cout << ans % mul << endl;
}
