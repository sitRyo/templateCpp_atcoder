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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
// #define MOD 1000000007 
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

const ll MOD = 1000000007;

inline ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

inline ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

inline void init() {
  fac[0] = 1;
  ifac[0] = 1;
  for (ll i = 0; i < 200010; ++i) {
    fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod M)
    ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
  }
}

inline ll perm(ll a, ll b){ // aPb
    if(a < b) return 0;
    ll tmp = ifac[a-b] % MOD;
    return tmp * fac[a] % MOD;
}

 
inline ll hcomb(ll n,ll k){
	if(n==0 && k==0) return 1;
	return comb(n+k-1,k);
}

int main() {
  ll n, m;
  cin >> n >> m;
  
  if (n < 3) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 3) {
    cout << 1 << endl;
    return 0;
  }

  init();
  ll all = comb(n + m - 2, n - 1);
  ll ans = 0;
  for (int i = 1; i <= min(n, m); ++i) {
    // if (m - i < 0 or i < m-i or n - i < 0 or n - i > i) continue;
    ans += comb(i,n-i)*hcomb(i,m-i) % MOD;
    ans %= MOD;
  }
  cout << (all - ans + MOD) % MOD << endl;
}
