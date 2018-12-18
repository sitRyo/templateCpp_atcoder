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

vector<int> sft;
int digit;

void dfs(int s, int count) {
  if (count > digit) return;
  int cpy = s;
  sft.pb(cpy);
  dfs(cpy + pow(10,count) * 3, count+1);
  dfs(cpy + pow(10,count) * 5, count+1);
  dfs(cpy + pow(10,count) * 7, count+1);
  return;
}

int main() {
  int n,cpy,res = 0; cin >> n;
  cpy = n;
  while (cpy > 0) {
    digit++;
    cpy /= 10;
  }

  dfs(3,1);
  dfs(5,1);
  dfs(7,1);

  sorti(sft);
  for (auto itr : sft) {
    bool s,f,t; s = f = t = false;
    if (itr > n) break;
    int cpy = itr;
    while (cpy > 0) {
      int dig = cpy % 10;
      if (dig == 3) t = true;
      if (dig == 5) f = true;
      if (dig == 7) s = true;
      cpy /= 10;
    }
    if (s and t and f) res++;
  }

  cout << res << endl;
}
