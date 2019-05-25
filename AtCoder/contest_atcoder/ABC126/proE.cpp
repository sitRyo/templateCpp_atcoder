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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m), z(m), ans(n+1, 0);

  map<int,int> mp, mp2;
  rep(i, m) {
    cin >> a[i] >> b[i] >> z[i];
    mp[a[i]] += 1;
    mp[b[i]] += 1;
  } 

  ll cnt = n;
  for (auto&& itr : mp) {
    if (itr.second > 1) cnt -= 1;
  }

  for (int i = 0; i < m; ++i) {
    ll p1 = a[i], p2 = b[i];
    if (mp[a[i]] >= 2  and mp[b[i]] >= 2) {
      mp2[b[i]] = 1, mp2[a[i]] = 1;
      cnt -= mp2[a[i]] + mp2[b[i]];
    } else if ((mp[a[i]] >= 2 and mp[b[i]] < 2) or (mp[a[i]] < 2 and mp[b[i]] >= 2)) {

      cnt -= mp2[a[i]] + mp2[b[i]];
      mp2[a[i]] = 0;
    } else if ((mp[a[i]] <= 1 and mp[b[i]] <= 1)) {
      cnt -= 1;
    }
  }

  cout << cnt << endl;
} 
