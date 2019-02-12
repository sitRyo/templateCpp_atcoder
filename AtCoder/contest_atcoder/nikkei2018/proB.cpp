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
  string a,b,c;
  int n;
  cin >> n;
  cin >> a;
  cin >> b;
  cin >> c;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    map<char, int> mp;
    mp[a[i]] += 1;
    mp[b[i]] += 1;
    mp[c[i]] += 1;
    vector<int> vec;
    for (auto itr : mp) {
      vec.push_back(itr.second);
    }
    sortd(vec);
    ans += 3 - vec[0];
  }
  cout << ans << endl;
}
