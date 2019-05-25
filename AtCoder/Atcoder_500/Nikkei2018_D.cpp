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

int main() {
  ll n,m;
  cin >> n >> m;
  vector<ll> t(m), l(m), r(m);
  set<ll> st;

  rep(i, m) {
    cin >> t[i] >> l[i] >> r[i];
  }

  for (int i = 1; i <= n; ++i) {
    st.insert(i);
  }

  ll ans = 0;

  for (int i = m - 1; i >= 0; --i) {
    ll left = l[i], right = r[i];
    auto itr = st.lower_bound(left);
    auto endt = st.begin();

    if (itr != st.end()) {
      bool flag = false;
      for (auto tt = itr; tt != st.end(); ++tt) {
        if (*tt > right) break;
        flag = true;
        ans += t[i];
        endt = tt;
      }
      
      if (flag) st.erase(itr, ++endt);
      // roll(st);
      // END;
    }
  }

  cout << ans << endl;
}
