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
  ll n, ans = 0;
  cin >> n;

  vector<vector<char> > data(n,vector<char>(n));

  rep(i,n)rep(j,n) {
    cin >> data[i][j];
  }

  rep(i,n)rep(j,n) {
    if (i > 0 and i < n-1 and j > 0 and j < n-1 and data[i][j] == 'X') {
      if (data[i-1][j-1] == 'X' and data[i-1][j+1] == 'X' and 
      data[i+1][j-1] == 'X' and data[i+1][j+1] == 'X') {
        ans += 1;
      }
    }
  }

  cout << ans << endl;
}
