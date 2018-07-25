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
#define MAX 10

ll N,K;
ll D[MAX];
ll a[MAX];

std::vector<int> v;

int main() {
  cin >> N >> K;
  rep(i,K) {
    int a;
    cin >> a;
    D[a] = 1;
  }

  int lim = 10 * N;

  for (int i = N; i <= lim; ++i) {
    int temp = i;
    bool flag = true;

    while (temp > 0) {
      int digit = temp % 10;
      if (D[digit]) {
        flag = false;
        break;
      }
      temp /= 10;
    }

    if (flag) {
      cout << i << endl;
      return 0;
    }
  }

}
