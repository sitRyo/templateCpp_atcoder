#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cmath>
#include <cstdlib>

#define INF 1000000000
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

using namespace std;
typedef long long ll;

ll N;
ll n;
std::vector<ll> data;

ll tt = 0;
ll k = 0;
ll temp;

int main() {
  scanf("%lld", &N);
  REP(i,N) {
    scanf("%lld", &temp);
    data.push_back(temp - (i+1));
  }

  sort(data.begin(), data.end());

  ll mid = N/2;
  temp = data[mid];

  for (auto itr = data.begin(); itr != data.end(); itr++) {
    tt += abs(*itr - temp);
  }

  printf("%lld\n", tt);
}
