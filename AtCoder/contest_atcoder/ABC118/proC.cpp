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
#include <set>
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

// 約数の列挙
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
  int n;
  cin >> n;
  vector<ll> a(n);

  rep(i,n) {
    cin >> a[i];
  }
  set<ll> st;
  map<ll,bool> mp;
  for (auto itr : div_count(a[0])) {
    st.insert(itr);
    mp[itr] = true;
  }

  ll ans = -1;
  for (int i = 1; i < n; ++i) {
    for (auto itr : mp) {
      if (itr.second) {
        if (itr.first > a[i] or a[i] % itr.first != 0) {
          mp[itr.first] = false;
        }
      }
    }
  }
  
  for (auto itr : mp) {
    if (itr.second)
      ans = max(ans, itr.first);
  }

  cout << ans << endl;
}
