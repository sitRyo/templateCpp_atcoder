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

ll judge(ll a) {
  if (a % 4 == 0) return a;
  if (a % 4 == 1) return 1;
  if (a % 4 == 2) return a + 1;
  return 0;
}

int main() {
  ll a,b;
  cin >> a >> b;

  cout << (judge(b) ^ judge(a-1)) << endl;
}
