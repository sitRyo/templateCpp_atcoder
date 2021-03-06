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
  int n,a,b;
  cin >> n >> a >> b;
  int total = 0, ans = 0;

  for (int i = 1; i <=n; ++i) {
    int cpy = i;
    while (cpy > 0) {
      total += cpy % 10;
      cpy /= 10;
    }
    if (total >= a and total <= b) {
      ans += i;
    }
    total = 0;
  }
  cout << ans << endl;
}
