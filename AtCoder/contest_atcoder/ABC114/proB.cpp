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
  string s; cin >> s;
  ll res = 1000;
  for (int i = 0; i <= s.size() - 3; ++i) {
    ll t = 0;
    t += 100 * (s[i] - '0');
    t += 10 * (s[i+1] - '0');
    t += s[i+2] - '0';
    if (abs(t-753) < res) res = abs(t-753);

  }

  cout << res << endl;
}
