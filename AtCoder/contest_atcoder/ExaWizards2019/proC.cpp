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

typedef pair<int,char> pc;
typedef pair<int,int> pt;

int main() {
  int n, q;
  cin >> n >> q;

  vector<char> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  char left = s.front(), right = s.back();
  int cntl = 0, cntr = 0;

  vector<pc> wiz(q);
  // 1番左, 1番右
  vector<int> cnt(n, 1);
  
  rep(i,q) {
    char t, d;
    cin >> t >> d;
    wiz[i] = make_pair(t, d);
    if (t == left and d == 'L') cntl += 1;
  }



  cout << ans << endl;
}
