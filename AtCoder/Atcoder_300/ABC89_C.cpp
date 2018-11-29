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
#define MAX 100000

int N;
string S;

ll ans = 0;
int num = 0;

ll D[5];
int P[10] = {0,0,0,0,0,0,1,1,1,2};
int Q[10] = {1,1,1,2,2,3,2,2,3,3};
int R[10] = {2,3,4,3,4,4,3,4,4,4};

int main() {
  ll m, a, r, c, h;
  m = a = r = c = h = 0;
  cin >> N;
  rep(i,N) {
    cin >> S;
    if (S[0] == 'M') m++;
    if (S[0] == 'A') a++;
    if (S[0] == 'R') r++;
    if (S[0] == 'C') c++;
    if (S[0] == 'H') h++;
  }

  D[0] = m; D[1] = a; D[2] = r; D[3] = c; D[4] = h;

  rep(i,10) {
    ans += D[P[i]] * D[Q[i]] * D[R[i]];
  }

  cout << ans << endl;
}
