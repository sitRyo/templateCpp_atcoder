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


/* add your algorithm here */

int main() {
  string s,t;
  cin >> s; cin >> t;
  ll mmax = max(s.size(), t.size());
  map<char, int> ms, mt;
  map<int, int> as, at;

  for (auto itr : s) {
    ms[itr] += 1;
  }

  for (auto itr : t) {
    mt[itr] += 1;
  }

  for (char ch = 'a'; ch <= 'z'; ch++) {
    as[ms[ch]] += 1;
    at[mt[ch]] += 1;
  }

  for (ll i = 0; i < mmax; ++i) {
    if (as[i] != at[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
