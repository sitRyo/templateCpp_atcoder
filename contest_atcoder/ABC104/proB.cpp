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
#include <ctype.h>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007

/* add vars here */

string S;

/* add your algorithm here */

int main() {
  cin >> S;

  if (S[0] != 'A') {
    cout << "WA" << endl;
    return 0;
  }

  int a;
  int count = 0;

  for (int i = 2; i <= S.size() - 2; ++i) {
    if (S[i] == 'C') {
      count++;
      a = i;
    }
  }

  if (count != 1) {
    cout << "WA" << endl;
    return 0;
  }

  for(int i = 1; i < S.size(); ++i) {
    if (i == a) {
      continue;
    }

    if (S[i] >= 'A' && S[i] <= 'Z') {
      cout << "WA" << endl;
      return 0;
    }
  }

  cout << "AC" << endl;
}
