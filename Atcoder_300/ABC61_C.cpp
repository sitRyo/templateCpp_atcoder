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

#define INF 10e10
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

ll N, K;
std::vector<P> data;

int main() {
  P vec;
  cin >> N >> K;
  REP(i,N) {
    scanf("%lld %lld", &vec.first, &vec.second);
    data.push_back(vec);
  }

  sort(data.begin(), data.end());

  ll total = 0;
  ll ans;
  bool flag = false;
  for (auto itr = data.begin(); itr != data.end(); itr++) {
    total += itr->second;
    if (K <= total) {
      ans = itr->first;
      flag = true;
    }
    if (flag) break;
  }

  printf("%lld\n", ans);
}
