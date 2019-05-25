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
  string s;
  cin >> n;
  cin >> s;

  map<int,int> mp;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    t[i] = s[i] - '0';
    mp[t[i]] += 1;
  }
  int teban = (n - 11) / 2;
  if (mp[8] < teban) {
    cout << "NO" << endl;
    return 0;
  }

  int cnt = 0;
  for (int i = 0; i < (n - 10); ++i) {
    if (t[i] == 8) cnt += 1;
  }

  if (cnt > (n - 10) / 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
