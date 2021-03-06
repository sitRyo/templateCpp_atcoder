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
  vector<int> a;
  rep(i,4) {
    ll b;
    cin >> b;
    a.pb(b);
  }

  sorti(a);
  if (a[0] == 1 and a[1] == 4 and a[2] == 7 and a[3] == 9) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
