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

/*
light on -> 1, off -> 0;

*/

int main() {
  int n;
  cin >> n;
  vector<int> light(n,0);
  rep(i,n) {
    cin >> light[i];
  }

  int ans = 0;
  for (int i = 1; i < n-1; ++i) {
    if (light[i] == 0) {
      if (light[i-1] && light[i+1]) {
        light[i+1] = 0;
        ans += 1;
      }
    }
  }

  cout << ans << endl;
}
