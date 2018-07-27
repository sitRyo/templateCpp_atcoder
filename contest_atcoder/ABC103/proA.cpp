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

int N;
ll a[3001];
ll sum = 0;

int main() {
  cin >> N;
  REP(i,N) {
    ll a;
    cin >> a;
    sum += a-1;
  }
  cout << sum << endl;
}
