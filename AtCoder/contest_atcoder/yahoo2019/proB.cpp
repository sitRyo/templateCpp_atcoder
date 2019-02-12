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
#include <map>
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
  map<int,int> mp;
  for (int i = 0; i < 3; ++i) {
    int a,b;
    cin >> a >> b;
    mp[a] += 1;
    mp[b] += 1;
  }

  for (auto itr : mp) {
    if (itr.second == 0 or itr.second > 2) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}
