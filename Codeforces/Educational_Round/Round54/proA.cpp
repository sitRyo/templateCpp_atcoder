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
  int n;
  string str;
  cin >> n;
  cin >> str;

  int empty = n-1;
  for (int i = 0; i < str.size() - 1; ++i) {
    if (str[i] > str[i+1]) {
      empty = i;
      break;
    }
  }

  cout << str.substr(0,empty) + str.substr(empty + 1) << endl;
}
