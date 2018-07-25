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
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 500

int N;
int C[MAX + 1];
ll S[MAX + 1];
int F[MAX + 1];

int main() {
  scanf("%d", &N);
  rep(i,N-1) cin >> C[i] >> S[i] >> F[i];

  rep(i,N-1) {
    ll tt = S[i] + C[i];
    for(int j = i+1; j < N-1; ++j) {
      ll c = tt - S[j];

      if (c < 0) {
        tt = S[j] + C[j];
        continue;
      }

      if (c % F[j] > 0) {
        ll next = F[j] - (c % F[j]);
        tt = tt + next + C[j];
      } else {
        tt = tt + C[j];
      }

    }

    cout << tt << endl;
  }

  cout << "0" << endl;
}
