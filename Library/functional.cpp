#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007 // 10^9 + 7
typedef long long ll;

// 階乗を計算 (MODなし)
ll factorial(ll n) {
  if (n == 1) return 1;
  return n * factorial(n-1);
}

// 階乗を計算 (MODあり) ※問題のMODと合致しているか？
ll factorial_mod(ll n) {
  ll ans = 1;
  for (ll i = n; i > 0; --i) {
    ans = (ans % MOD) * (i % MOD) % MOD;
  }
  return ans;
}

int main() {
  ll a;
  cin >> a;
  cout << factorial_mod(a) << endl;
}
