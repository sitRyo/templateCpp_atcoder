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

ll n,x;

int main() {
  cin >> n >> x;
  vector<ll> a(n,0);

  rep(i,n) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());


  int cnt = 0, ans = 0;
  while (x > 0 && cnt < n) {
    if (a[cnt] <= x) {
      if (cnt == n-1) {
        if (a[cnt] == x) {
          ans++;
        }
      } else {
        ans++;
        x -= a[cnt];
      }
    }
    cnt++;
  }

  cout << ans << endl;
}
