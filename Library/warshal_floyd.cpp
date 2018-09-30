#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define N 10000

ll cost[N][N];

void floyd_warshall() {
  for (ll k = 0; k < N; ++k) {
    for (ll i = 0; i < N; ++i) {
      for (ll j = 0; j < N; ++j) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }
}
