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
vector<int> v;

void gen_primes() {
  v.push_back(2),v.push_back(3);
  for (int i = 4; i < 1000; ++i) {
    bool flag = true;
    for (int j = 2; j < i; ++j) {
      if (i % j == 0) {
        flag = false;
        break;
      }
    }
    if (flag) v.push_back(i);
  }
}

int main() {
  cin >> N;
  gen_primes();
  vector<int> d;

  for (auto itr = v.begin(); itr != v.end(); itr++) {
    int t = *itr;
    int tt = 0;

    while (t <= N) {
      tt += N / t;
      t *= *itr;
    }

    if (tt != 0){
      d.push_back(++tt);
    }
  }

  ll ans = 1;
  const long MOD = 1000000007;

  for (auto itr = d.begin(); itr != d.end(); ++itr) {
    ans *= *itr;
    ans %= MOD;
  }

  cout << ans << endl;
}
