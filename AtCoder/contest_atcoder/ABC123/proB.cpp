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

int main() {
  vector<int> a(5);
  rep(i,5) {
    cin >> a[i];
  }

  sorti(a);
  ll ans = 10000000;
  do {
    ll temp = 0;
    int cnt = 0;
    for (auto itr : a) {
      cnt += 1;
      if (itr % 10 != 0 and cnt != 5) {
        temp += itr + (10 - itr % 10);
      } else {
        temp += itr;
      }
    }
    ans = min<ll>(ans, temp);
  } while(next_permutation(a.begin(), a.end()));

  cout << ans << endl;
}
