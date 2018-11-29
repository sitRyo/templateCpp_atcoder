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
  ll a,b,k;
  cin >> a >> b >> k;

  for (int i = 0; i < k; ++i) {


    if (i % 2 == 0) {
      if (a % 2 == 1) {
        a -= 1;
      }
      b += a / 2;
      a /= 2;
    } else {
      if (b % 2 == 1) {
        b -= 1;
      }
      a += b / 2;
      b /= 2;
    }
  }

  cout << a << " " << b << endl;
}
