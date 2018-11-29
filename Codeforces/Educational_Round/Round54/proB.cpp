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
#include <climits>
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

/*
ある自然数の素因数で最小のものは,
(i) 偶数 -> 2
(ii) 奇数 -> 3から √n までの自然数m で, n % m == 0となる最小の自然数
それは明らかに素数
素因数は素数, 考え方としてはエラトステネスのふるいと同じ

ある自然数nに対して，nの最小の素因数を引いていく
素因数は素数
*/

ll ret_min_prime(ll n) {
  for (int i = 2; i * i <= n; ++i) {
    cout << i*i << endl;
    if (n % i == 0) {
      return i;
    }
  }
  return n;
}

int main() {
  ll n; cin >> n;

  if (INT_MAX < n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  /*
  ll cnt = 0;
  if (n % 2 != 0) {
    n -= ret_min_prime(n);
    cnt++;
  }
  cnt += n / 2;
  cout << cnt << endl;
  */
}
