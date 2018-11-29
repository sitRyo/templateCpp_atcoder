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
かえる ->
1回目 a飛ぶ, 2回目 b飛ぶ
2回で(a-b)移動する

num = k / 2;

kが奇数
num * (a-b) + b

kが偶数
num * (a-b)
*/

int main() {
  int num;
  cin >> num;

  for (int i = 0; i < num; ++i) {
    ll a,b,k;
    cin >> a >> b >> k;

    ll dis = a-b;
    ll div = k/2;

    if (k % 2 == 0) {
      cout << dis * div << endl;
    } else {
      cout << dis * div + a << endl;
    }
  }
}
