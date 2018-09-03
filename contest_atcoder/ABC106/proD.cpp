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

#define INF 10e8
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

typedef pair<int,int> ip;

/* add vars here */

ll n,m,q;
vector<ip> lr, pq;
int b[501];
int r[501];

/* add your algorithm here */

int main() {
  cin >> n >> m >> q;

  ip P;

  rep(i,n+1) {
    b[i] = 0;
  }

  rep(i,m) {
    scanf("%d %d", &P.first, &P.second);
    b[P.first]++;
    lr.pb(P);
  }

  rep(i,q) {
    scanf("%d %d", &P.first, &P.second);
    pq.pb(P);
  }

  rep(i,n+1) {
    cout << b[i] << endl;
  }

  r[1] = b[1];
  for (int i = 2; i <= n; ++i){
    r[i] = b[i-1] + b[i];
  }


  sort(lr.begin(), lr.end());
  sort(pq.begin(), pq.end());

  for (int i = 0; i < pq.size(); ++i) {
    int a , b;
    a = r[pq[i].first - 1] ;
    b = r[pq[i].second] ;
    ll ans = 0;
    for (int j = a; j <= b; ++j) {
      if (lr[j].second <= pq[j].second) ++ans;
    }

    cout << ans << endl;
  }

}
