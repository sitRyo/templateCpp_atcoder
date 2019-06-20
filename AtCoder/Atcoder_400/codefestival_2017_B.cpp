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
  string s;
  cin >> s;

  map<char, int> mp;
  rep(i,s.size()) {
    mp[s[i]] += 1;
  }

  int a,b,c,t,p;
  a = mp['a'];
  b = mp['b'];
  c = mp['c'];

  t = min({a,b,c});
  p = max({a,b,c});

  if (abs(t-p) < 2) {
    cout << "YES"<< endl;
  } else {
    cout << "NO" << endl;
  }
}