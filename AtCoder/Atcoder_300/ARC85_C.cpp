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
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

/*
M -> 1900ms 1/2で正解
M-N -> 100ms 必ず正解
プログラムの実行時間の総和の期待値をXmsとしたとき，Xを出力せよ

N <= 5のときには M = N;
N > 5のときには M = 5;


*/

int main() {
  int n,m;
  cin >> n >> m;

  int p = (int)pow(2,m);
  int correct = n - m;
  ll ans = 0;
  ll total_n = p * correct * 100;
  ll total_m = p * m * 1900;

  ll total = total_n + total_m;

  cout << total << endl;
}
