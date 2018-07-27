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

#define INF 10e10
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

int main() {
  string s,t;
  cin >> s;
  cin >> t;

  int lim = s.size();

  string ss = s, tt = t;
  int count = 0;

  for (int i = lim-1; i >=0; --i) {


      bool flag = false;
      for (int j = 0; j < lim; ++j) {
        int a = (i+j) % lim;
        if (s[a] != t[j]) {
          flag = true;
          break;
        }
      }

      if (flag) {
        continue;
      } else {
        cout << "Yes" << endl;
        return 0;
      }
  }

  cout << "No" << endl;
}
