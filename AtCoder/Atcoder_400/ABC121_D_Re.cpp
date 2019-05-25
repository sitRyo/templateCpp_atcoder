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

ll addsolve(ll a) { return (a + 1) / 2 % 2; }
ll solve(ll a) {
  if (a % 2 == 1) return addsolve(a);
  else return addsolve(a + 1) ^ (a + 1);
}

int main() {
  ll a,b;
  cin >> a >> b;

  cout << (solve(b) ^ solve(a-1)) << endl;
}
