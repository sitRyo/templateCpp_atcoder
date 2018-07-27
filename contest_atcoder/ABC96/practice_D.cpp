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

#define INF 1000000000
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 55

using namespace std;

vector<int> primes;

// エラトステネスの篩
void sieve(int N) {
  std::vector<int> v;
  for (int i=0; i<N; i++) {
    v.push_back(1);
  }

  for (int i=2; i<sqrt(N); i++) {
    if (v[i]) {
      for (int j=0; i*(j+2) < N; j++) {
        v[i *(j+2)] = 0;
      }
    }
  }

  for (int i=2; i<N; i++) {
    if (v[i]) {
      primes.push_back(i);
    }
  }
}

int N;
int dp[MAX + 5];
std::vector<int> v;

int main() {
  std::vector<int> five_primes;

  scanf("%d", &N);
  sieve(55555);

  REP(i,primes.size()) {
    if (primes[i] % 5 == 1) {
      five_primes.push_back(primes[i]);
    }
  }

  REP(i,N) {
    printf("%d ", five_primes[i]);
  }

  cout << endl;
}
