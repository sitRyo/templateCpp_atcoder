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
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int l;
vector<ll> a;

int main() {
  cin >> l;
  a = vector<ll>(l);
  ll cnt = 0;
  vector<ll> sum(l+1), revsum(l+1);
  sum[0] = 0; revsum[l] = 0;
  rep(i,l) {
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
  }


  for (int i = l-1; i >= 0; --i) {
    revsum[i] = revsum[i+1] + a[i];
  }

  if (l == 1) {
    cout << 0 << endl;
    return 0;
  }

  // cout << "******" << endl;
  ll ans = INF;
  ll temp = 0;
  for (int i = 1; i < l; ++i) {
    ll tmpans = temp + sum[l] - sum[i+1];
    ans = min(ans, tmpans);
    if (a[i] % 2 == 0) {
      temp += 1;
    }
  }
  
  temp = 0;
  for (int i = l - 2; i >= 0; --i) {
    ll tmpans = temp + revsum[0] - revsum[i];
    ans = min(ans, tmpans);
    if (i == 0) {
      temp += 0;
    } else if (a[i] % 2 == 0) {
      temp += 1;
    }
  }

  cout << ans - cnt << endl;
}
