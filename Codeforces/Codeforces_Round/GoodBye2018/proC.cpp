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
#include <set>
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
set<T> div_count(T x) {
  set<T> st;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      st.insert(i);
      st.insert(x/i);
    }
  }
  return st;
}

int main() {
  ll n;
  cin >> n;

  set<ll> ans;
  for (auto itr : div_count(n)) {
    ll cnt = n / itr, times = cnt - 1, total, relt;

    // cout << "yakusuu: " << itr << endl;
    // cout << "cnt: " << cnt << endl;
    // cout << "times: " << times << endl;
    
    total = (times * (times + 1)) / 2;
    // cout << "total: " << total << endl;
    
    relt = total * itr + cnt;
    // cout << relt << endl;
    ans.insert(relt);
  }

  for (auto itr : ans) {
    cout << itr << " ";
  } END;
}
