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
#include <set>
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

  vector<int> t(n);
  for (int i = 0; i < n; ++i) { 
    t[i] = s[i] - 'a';
  }

  pair<int, int> p = make_pair(t.back(), n);
  for (int i = n - 2; i >= 0; --i) {
    if (t[i] < p.first) {
      p.first = t[i];
      p.second = i + 1;
    } else if (t[i] > p.first) {
      cout << "YES" << endl;
      cout << i + 1 << " " << p.second << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}
