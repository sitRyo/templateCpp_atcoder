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
typedef unsigned long long ull;

#define INF 10e10
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 300

ll T;
ull A[MAX], B[MAX], C[MAX], D[MAX];

int main() {

  scanf("%lld", &T);

  for (int i = 0; i < T; ++i) {
    scanf("%llu %llu %llu %llu", &A[i], &B[i], &C[i], &D[i]);
    cout << A[i] << endl;
  }

  REP(i,T) {

    if (A[i] < B[i] || B[i] > D[i]) {
      cout << "No" << endl;
      continue;
    }

    if (B[i] == C[i]) {
      cout << "Yes" << endl;
      continue;
    }

    if (B[i] == D[i]) {
      if (A[i] % B[i] > C[i]) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
      continue;
    }

    // inc > 0
    ull first = A[i] - B[i];
    ull inc = D[i] - B[i];

    ull target = C[i] - first;
    ull temp = C[i] + target % inc;

    cout << temp << endl;

    if (temp == C[i] || temp == B[i]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }

  }
}
