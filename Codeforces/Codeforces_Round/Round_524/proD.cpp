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
  ll r = 2,g = 5,b = 8;
  ll n,k;
  cin >> n >> k;

  r *= n;
  g *= n;
  b *= n;



  ll rs, gs, bs;
  rs = ceil((double)r / k);
  gs = ceil((double)g / k);
  bs = ceil((double)b / k);

  cout << rs + gs + bs << endl;
}
