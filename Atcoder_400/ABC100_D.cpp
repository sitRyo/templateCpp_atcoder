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

int main() {
  int N,M;
  cin >> N >> M;
  vector<long long> a[3];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      long long num; cin >> num;
      a[j].pb(num);
    }
  }

  long long res = 0;
  // ビット全探索
  for (int bit = 0; bit < (1 << 3); ++bit) {
    vector<long long> b;
    for (int i = 0; i < N; ++i) {
      long long tmp = 0;
      for (int j = 0; j < 3; ++j) {
        // 絶対値をとるという操作は, 「そのまま」と「-1倍したもの」の大きい方を選ぶ操作
        if (bit & (1 << j)) tmp += a[j][i];
        else tmp -= a[j][i];
      }
      b.pb(tmp);
    }
    sort(b.begin(), b.end(), greater<long long>());
    long long sum = 0;
    for (int i = 0; i < M; ++i) {
      sum += b[i];
    }

    res = max(res, sum);
  }
  cout << res << endl;
}
