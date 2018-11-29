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

/*
累積和を取る
1番
*/

int main() {
  ll n;
  cin >> n;
  vector<ll> isgood(n,0);
  ll first = -1, second = -1;
  ll sum = 0;
  vector<ll> cpy(n,0);
  rep(i,n) {
    cin >> isgood[i];
    cpy[i] = isgood[i];
    sum += isgood[i];
  }

  sortd(cpy);
  first = cpy[0], second = cpy[1];

  vector<ll> ans;
  rep(i,n) {
    ll target = isgood[i], mmax;
    if (target == first) {
      mmax = second;
    } else {
      mmax = first;
    }
    ll con = sum - (target + mmax);

    if (con == mmax) {
      ans.pb(i+1);
    }
  }

  cout << ans.size() << endl;
  rep(i,ans.size()) {
    cout << ans[i] << " ";
  }
  END;
}
