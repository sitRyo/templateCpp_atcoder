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

int main() {
  int n,a,b;
  cin >> n >> a >> b;

  int d = a - b;
  if (d % 2 == 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Borys" << endl;
  }
}
