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
  int n;
  cin >> n;
  vector<ll> l(n);
  ll mmax = -1,sum = 0;
  rep(i,n) {
    ll lll;
    cin >> lll;
    mmax = max(mmax, lll);
    sum += lll;
  }

  sum -= mmax;
  if (mmax < sum) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
