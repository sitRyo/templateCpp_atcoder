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

int main() {
  string s;
  ll x,n;
  cin >> n >> x;
  cin >> s;
  vector<ll> t(n);
  rep(i,n) {
    cin >> t[i];
  }

  ll ans = 0;
  rep(i,n) {
    char ch = s[i];
    if (s[i] == '0') {
      ans += t[i];
    } else {
      if (t[i] > x) {
        ans += x;
      } else {
        ans += t[i];
      }
    }
  }

  cout << ans << endl;
}
