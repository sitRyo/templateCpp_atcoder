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
  ll w1,h1,w2,h2,ans = 0;

  cin >> w1 >> h1 >> w2 >> h2;

  if (w1 == w2) {
    ll tmp1 = h1 + h2, tmp2 = w1;
    cout << (tmp1 * 2) + (tmp2 * 2) + 4 << endl;
  } else {
    ll tmp1 = h1 + h2, tmp2 = w1;
    ans = (tmp1 * 2) + (tmp2 * 2) + 4;
    cout << ans << endl;
  }

}
