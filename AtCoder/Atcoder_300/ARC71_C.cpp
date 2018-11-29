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

vector<string> s;

/* add your algorithm here */

int main() {
  int n;
  cin >> n;
  rep(i,n) {
    string t;
    cin >> t;
    s.pb(t);
  }

  map<char,int> m;

  rep(i,s[0].size()) {
    m[s[0][i]]++;
  }


  for (int i = 1; i < s.size(); ++i) {
    map<char,int> tm;
    for (int j = 0 ; j < s[i].size(); ++j) {
      char t = s[i][j];
      tm[t] += 1;
    }

    for (auto itr = m.begin(); itr != m.end(); ++itr) {
      char v = itr->first;
      int c = itr->second;

      if (tm[v] != c) {
        if (tm[v] == 0) {
          itr->second = 0;
        } else if (tm[v] < c){
          itr->second = tm[v];
        }
      }
    }
  }

  for (int i = 0; i < 26; ++i) {
    int t = 'a' + i;
    for (int i = 0; i < m[t]; ++i) {
      cout << (char)t;
    }
  }

  cout << endl;
}
