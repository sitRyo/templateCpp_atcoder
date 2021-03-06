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
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

ll N;
vector<int> data;

/* add your algorithm here */

int main() {
  cin >> N;

  string ans = "";
  while (N != 0) {
    if (N % (-2) != 0) {
      N--;
      ans = "1" + ans;
    } else {
      ans = "0" + ans;
    }

    N /= -2;
  }

  if (ans.empty()) ans = "0";
  cout << ans << endl;
}
