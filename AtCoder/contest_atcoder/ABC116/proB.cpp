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
  int s;
  cin >> s;
  map<ll,bool> t;
  ll tmp = s;
  t[s] = true;
  for (int i = 2; ; ++i) {
    if (tmp % 2 == 0) {
      tmp = tmp / 2;
    } else {
      tmp = 3 * tmp + 1;
    }
    if (t[tmp]) {
      cout << i << endl;
      return 0;
    } else {
      t[tmp] = true;
    }
  }
}
