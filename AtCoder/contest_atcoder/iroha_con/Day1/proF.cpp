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
#include <map>
#include <cmath>
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
  cin.tie(0); ios::sync_with_stdio(false);
  ll n, k, cnt = 0, cnt2 = 0;
  cin >> n >> k;

  vector<ll> ans;
  map<ll,ll> mp = factorize(n);
  for (auto&& itr : mp) {
    cnt2 += itr.second;
  }

  if (cnt2 < k) {
    cout << -1 << endl;
    return 0;
  }

  ll store = 1;
  for (auto&& itr : mp) {
    if (cnt + itr.second < k) {
      for (int i = 0; i < itr.second; ++i) {
        cout << itr.first << ' ';
      }
      cnt += itr.second;
    } else {
      int t = 0;
      for (int i = cnt; i < k - 1; ++i) {
        cout << itr.first << ' ';
        cnt = k;
        t += 1;
      }
      for (int i = t; i < itr.second; ++i) {
        // debug(i);
        store *= itr.first;   
      }
     
    }
  }

  if (store != 1) cout << store;
  END;
}
