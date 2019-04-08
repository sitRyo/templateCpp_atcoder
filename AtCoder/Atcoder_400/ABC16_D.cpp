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

typedef pair<double,double> pd;
typedef pair<int,int> pi;

int cross(int x1, int y1, int x2, int y2, int x, int y) {
  return (x1 - x2) * (y - y1) + (y1 - y2) * (x1 - x);
}

int main() {
  double Ax, Ay, Bx, By;
  cin >> Ax >> Ay >> Bx >> By;
  int n;
  cin >> n;
  vector<pd> xy(n);
  rep(i,n) cin >> xy[i].first >> xy[i].second;

  int ans = 0;  

  for (int i = 0; i < n; i++) {
    int next = (i + 1) % n;
    double cx = xy[i].first, cy = xy[i].second;
    double dx = xy[next].first, dy = xy[next].second;

    double tc = cross(Ax, Ay, Bx, By, cx, cy);
    double td = cross(Ax, Ay, Bx, By, dx, dy);
    
    double ta = cross(cx, cy, dx, dy, Ax, Ay);
    double tb = cross(cx, cy, dx, dy, Bx, By);

    if (ta * tb < 0 and ta * tb < 0) {
      ans += 1;
    }
  }
  cout << (ans / 2) + 1 << endl;
}
