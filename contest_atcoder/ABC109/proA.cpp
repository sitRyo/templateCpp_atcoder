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
  cin >> a >> b;
  ll t = a * b;
  if (t % 2 == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
