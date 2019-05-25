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
  string s;
  cin >> s;

  map<char, ll> mp;

  for (auto itr : s) {
    mp[itr] += 1;
  }
  vector<ll> odd, even;
  ll ans = 0;
  for (auto itr : mp) {
    if (itr.second % 2 == 0) even.push_back(itr.second);
    else odd.push_back(itr.second);
  }

  sorti(odd);
  sorti(even);
  ll t = 0;
  for (auto itr : even) {
    t += itr;
  }
  if (!odd.empty()) {
    for (int i = 0; i < odd.size(); ++i) {
      if (i == odd.size() - 1) {
        t += odd[i];
        continue;
      } else if (odd[i] >= 3) {
        t += odd[i] - 1;
      }
      ans += 1;
    }
  }


  ans += t * t;

  cout << ans << endl;
}
