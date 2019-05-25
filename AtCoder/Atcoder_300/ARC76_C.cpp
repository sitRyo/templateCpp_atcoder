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
#include <array>
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

template <class C, class T>
constexpr void func(C & arr, T N) {
  arr[0] = 1;
  for (int i = 1; i < N; ++i) {
    arr[i] = (arr[i-1] * i) % MOD;
    arr[i] %= MOD;
  }
}

int main() {

  constexpr ll K = 100005;
  ll t1[K], t2[K];

  func(t1, K);
  func(t2, K);
  ll n, m;
  cin >> n >> m;


  if (abs(n - m) >= 2) {
    cout << 0 << endl;
    return 0;
  }


  if (abs(n - m) == 1) {
    cout << (t1[n] * t2[m]) % MOD << endl;
  } else {
    cout << (t1[n] * t2[m] * 2) % MOD << endl;
  }
}
