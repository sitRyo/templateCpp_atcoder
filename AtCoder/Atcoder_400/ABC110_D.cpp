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

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back

int main() {
  string s,t;
  cin >> s;
  cin >> t;
  map<char, char> mp;

  for (int i = 0; i < s.length(); ++i) {
    char t1 = s[i], t2 = t[i];
    if (mp[t1] == 0) {
      mp[t1] = t2;
    } else {
      if (mp[t1] != t2) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
}
