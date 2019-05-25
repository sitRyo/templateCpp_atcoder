/*
 * No.737 popcount
 * 
 * 2進数の桁DP...考え方は10進数のときと同じだろうけど苦手...
 * i桁目まで見たときに i-1桁のv(x)を求める方法がわからない
 */ 


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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

ll A;
ll dp[62][62][2];
ll num[62][62][2];

void solve() {
  cin >> A;
  num[0][0][1] = 1;
  rep(i, 60) {
    rep(j, 61) {
      ll m = (1LL << (59 - i));

      (dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
      
    }
  }
}

int main() { solve(); }