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
#define rep_r(m,i,n) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back

int main() {
  string s;
  cin >> s;

  map<char, bool> mp;

  for (auto itr : s) mp[itr] = true;

  if (s.size() < 26) {
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      if (!mp[ch]) {
        s.pb(ch);
        break;
      }
    }
    cout << s << endl;
  } else {
    string t = s;
    if (!next_permutation(s.begin(), s.end())) {
      cout << -1 << endl;
      return 0;
    }

    for (int i = 0; i < 26; ++i) {
      if (t[i] == s[i]) {
        cout << t[i];
      } else {
        cout << s[i];
        break;
      }
    }

    END;
  }
}
