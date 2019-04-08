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

void solve(vector<int> &v, vector<int> &w, int &n, int judge) {

  switch(judge) {
    // 0 -> v
    case 0: {
      ll dp[n+1][2000003];
      rep(i, n+1) rep(j, 2000003) dp[i][j] = INF;
      
      rep(i,n+1) dp[i][0] = 0;

    }
  }

}

int main() {
  int n,weight;
  cin >> n >> weight;
  vector<int> v(n), w(n), judge(3,1);
  int vmax = 1000000010, wmax = 1000000010;

  if (n > 30) judge[2] = 0;

  rep(i,n) {
    cin >> v[i] >> w[i];
    vmax = max(v[i], vmax);
    wmax = max(w[i], wmax);

    if (v[i] > 1000) judge[0] = 0;
    if (w[i] > 1000) judge[1] = 0;
  }

  for (int i = 0; i < 3; ++i) {
    if (judge[i]) solve(v, w, n, i);
  }
}
