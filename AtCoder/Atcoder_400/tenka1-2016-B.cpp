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
#include <stack>
using namespace std;

typedef long long ll;

#define INF 10e8 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int dp[101][101][101];
int able[101];
string S;

int rec(int idx, int depth, int last) {
  if (depth < 0) return INF;

  if (idx == S.size()) {
    if (depth == 0) return (last - idx);
    else return INF;
  }

  
}

int main() {
  cin >> S;
  memset(dp, -1, sizeof(dp));
  
}
