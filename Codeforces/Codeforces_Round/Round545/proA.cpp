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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n;
  cin >> n;
  vector<int> sushi(n + 1, -1);
  rep(i,n) {
    cin >> sushi[i];
  }

  bool flag = false;
  int ans = 0, now = sushi[0];
  int one = 0, two = 0;
  
  for (int i = 0; i < n; ++i) {
    if (sushi[i] == 1) {
      if (flag) {
        ans = max(min(one, two) * 2, ans);
        one = 0;
        flag = false;
      }
      one += 1; 
    } else {
      if (flag) {
        ans = max(min(one, two) * 2, ans);
        two = 0;
        flag = false;
      }
      two += 1;
    }

    if (sushi[i] != sushi[i+1]) {
      flag = true;
    }
  }

  ans = max(min(one, two) * 2, ans);
  cout << ans << endl;
}
