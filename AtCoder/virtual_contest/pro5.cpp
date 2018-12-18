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
#include <map>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

template<typename T>
map<T, long long> factorize(T x) {
  map<T, long long> res;
  for (long long i = 2; i * i <= x; ++i) {
    while (x % i == 0) {
      x /= i;
      res[i] += 1;
    }
  }
  if (x != 1) res[x]++;
  return res;
}

int main() {
  int n; cin >> n;
  vector<ll> fac(n+1, 0);

  for (int i = 1; i <= n; ++i) {
    for (auto itr : factorize(i)) {
      fac[itr.first] += itr.second;
    }
  }
  ll res = 0;
  for (auto itr : fac) if (itr > 73) res++;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i != j) {
        if (fac[i] >= 24 and fac[j] >= 2) res++;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        if (fac[i] >= 4 and fac[j] >= 14) res++;
      }
    }
  }

  ll tmp = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i != j) {
        for (int k = 0; k <= n; ++k) {
          if (i != k and j != k and fac[k] >= 2 and fac[i] >= 4 and fac[j] >= 4) {
            tmp++;
          }
        }
      }
    }
  }
  res += tmp / 2;

  cout << res << endl;
}
