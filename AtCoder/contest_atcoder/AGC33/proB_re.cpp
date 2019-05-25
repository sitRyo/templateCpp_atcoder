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

int main() {
  int h,w,n;
  cin >> h >> w >> n;
  int sc, sr;
  cin >> sr >> sc;

  string s,t;
  cin >> s;
  cin >> t;
  
  ll sumc[n+1], sumr[n+1];
  sumc[0] = sumr[0] = 0;

  for (int i = 1; i <= n; ++i) {
    
  }
  for (int i = 1; i <= n; ++i) {
    
  }
  cout << "YES" << endl;
}
