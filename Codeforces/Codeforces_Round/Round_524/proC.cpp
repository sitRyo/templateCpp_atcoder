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
  ll t, n, m;
  cin >> t;
  rep(i,t) {
    cin >> n >> m;
    ll total = n * m;
    ll ax1,bx1,cy1,dy1,ax2,bx2,cy2,dy2;
    ll black, white;
    black = total / 2; white = total / 2;
    cin >> ax1 >> bx1 >> cy1 >> dy1 >> ax2 >> bx2 >> cy2 >> dy2;

    if (ax1 >= ax2 && ax)
    cout << white << " " << black << endl;
  }
}
