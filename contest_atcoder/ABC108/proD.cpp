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
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll a,b;
string s;

/* add your algorithm here */

int main() {
  cin >> a;
  if (a % 2 == 0) {
    b = a / 2;
    b *= b;
    cout << b << endl;
  } else {
    b = a / 2;
    int c = b * (b + 1);
    cout << c << endl;
  }
}
