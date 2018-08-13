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

ll N;
ll divs = 0;
ll primes[1005];

void gen_primes() {
  rep_r(i,N,2) {

    if (!(i % 2)) continue;

    for (int j = 3; j < i / 2; ++i) {
      if (!(i % j)) continue;
    }


  }
}

int main() {
  cin >> N;

  for (int i = 0; )
}
