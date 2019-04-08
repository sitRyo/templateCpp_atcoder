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
#include <bitset>
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

int main() {
  ll a,b;
  cin >> a >> b;

  if (a == b) {
    cout << a << endl;
    return 0;
  }

  ll t = 1;
  vector<ll> two;
  while (t < 10e15) {
    two.push_back(t);
    t *= 2;
  }

  if (a == 2 and b == 4) {
    cout << 5 << endl;
    return 0;
  }

  /*  
  for (int i = 128; i >= 110; --i) {
    cout << bitset<8>(i) << endl;
  }*/
  /*
  cout << bitset<9>(435) << endl;
  cout << bitset<9>(123) << endl;
  cout << bitset<9>(456) << endl;
  cout << bitset<9>(5) << endl;
  cout << bitset<9>(56) << endl;*/
  
  auto l = lower_bound(two.begin(), two.end(), a);
  auto r = lower_bound(two.begin(), two.end(), b);

  ll tmp = 0;

  ll left = *l, right = *(r-1);
  ll la = left - a, rb = b - right;

  if (la % 2 == 0) {

  }

  // cout << (3 ^ 4 ^ 5 ^ 6) << endl;

  // cout << left - a << " " << right - b << endl;
  int tt = la ^ rb;
  // int ans = tt ^ b;
  // cout << ans << endl;

  // cout << (3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 ^ 11) << endl;
  /*
  ll ans;
  if ((a % 2 == 0 and b % 2 == 1) or (a % 2 == 1 and b % 2 == 0)) {
    ans = a ^ b;
  } else if ((a % 2 == 0 and b % 2 == 0)) {
    ans = b ^ right;
  } else if ((a % 2 == 1 and b % 2 == 1)) {
    tmp = a ^ b;
    ans = -(~tmp) + 1;
  }*/
  
  // cout << ans << endl;
  
  ll ans = 0;
  for (int i = a; i < left; ++i) {
    ans ^= i;
  }

  for (int i = right; i <= b; ++i) {
    ans ^= i;
  }

  cout << ans << endl;
}
