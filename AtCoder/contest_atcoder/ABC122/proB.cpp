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
  string s;
  cin >> s;
  int mmax = -1;
  for (int i = 0; i < s.size(); ++i) {
    int start = 0;
    for (int j = i; j < s.size(); ++j) {
      if (s[j] == 'A' or s[j] == 'C' or s[j] == 'G' or s[j] == 'T') start += 1;
      else break;
    }

    mmax = max(start, mmax);
  }

  cout << mmax << endl;
}
