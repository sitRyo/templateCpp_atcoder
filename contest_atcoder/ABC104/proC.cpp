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
typedef pair<ll,ll> P;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007

/* add vars here */

int D;
ll G;
P p[101];
ll ans = 0;
int mmax = 0;

/* add your algorithm here */

int main() {
  cin >> D >> G;

  rep(i,D) {
    cin >> p[i].first >> p[i].second;
    mmax += p[i].first;
  }

  for (int a = 0; a < p[0].first; a++) {

  
  }
}
