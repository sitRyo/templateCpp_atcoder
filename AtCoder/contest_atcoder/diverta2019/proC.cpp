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
  int n;
  cin >> n;
  vector<string> str;
  string t;
  ll ans = 0;

  map<int, int> mp;
  rep(i, n) {
    cin >> t;
    int s = t.size();
    rep(j, s-1) {
      if (t[j] == 'A' and t[j + 1] == 'B') ans += 1;
    }
    str.push_back(t);

    if (t.front() == 'B' and t.back() == 'A') mp[0] += 1;
    else if (t.front() == 'B') mp[1] += 1;
    else if (t.back() == 'A') mp[2] += 1;
    else mp[3] += 1;
  }
  
  if (mp[0] > 0) {
    ans += mp[0] - 1;
  }
  if (mp[0] > 0 and (mp[1] > 0 or mp[2] > 0)) {
    mp[2] += 1; // 先頭Bを1つ追加
    mp[1] += 1; // 末尾Aを1つ追加
  }

  ans += min(mp[2], mp[1]);
  cout << ans << endl;
}
