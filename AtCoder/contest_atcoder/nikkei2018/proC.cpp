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
  int n;
  cin >> n;

  vector<ll> a(n), b(n), plus(n);
  ll sumb = 0, sum = 0;

  rep(i,n) {
    cin >> a[i] >> b[i];
    plus[i] = a[i] + b[i];
    sumb += b[i];
  }
  sortd(plus);
  bool flag = true;
  rep(i,n) {
    if (flag) sum += plus[i];
    flag = !flag;
  }
  cout << sum - sumb << endl;
}
