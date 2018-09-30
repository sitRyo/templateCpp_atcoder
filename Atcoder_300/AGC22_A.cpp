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
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

string s;

/* add your algorithm here */

int main() {
  cin >> s;

  map<char, int> mp;

  rep(i,s.size()) {
    mp[s[i]] = 1;
  }

  string res(s);

  if (s.size() < 26) {
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      if (!mp[ch]) {
        s.pb(ch);
        break;
      }
    }
    cout << s << endl;
    // S.size = 26
  } else {
    if (!next_permutation(s.begin(), s.end())) {
      cout << -1 << endl;
      return 0;
    }

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == res[i]) continue;
      s.erase(s.begin() + i + 1, s.end());
      break;
    }

    cout << s << endl;
  }

}
