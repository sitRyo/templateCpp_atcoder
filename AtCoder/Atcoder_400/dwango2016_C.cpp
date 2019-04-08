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
  vector<int> a(n);
  map<int,int> num;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    num[a[i]] += 1;
  }

  ll ans = 0;

  ans += num[4];
  ans += num[3];
  num[1] = max(0, num[1] - num[3]);

  ans += num[2] / 2;
  if (num[2] % 2 == 1) {
    ans += 1;
    num[1] = max(0, num[1] - 2);
  }

  ans += (num[1] + 3) / 4;

  cout << ans << endl;
}
