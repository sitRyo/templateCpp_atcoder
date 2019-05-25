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
#define dubug(x) std::cout << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

typedef pair< pair<int,int>, pair<int,int> > pdi;

int main() {
  int h,w;
  cin >> h >> w;

  vector< vector<ll> > a(h + 1, vector<ll>(w + 1));
  vector<pdi> ans;

  rep(i,h) rep(j,w) {
    cin >> a[i][j];
  }

  auto count_from_left = [&](int high) {
    for (int now = 0; now < w; ++now) {
      pair<int,int> p1, p2;
      if (a[high][now] % 2) {
        if (now == w - 1 and high < h - 1) {
          p1.first = high;
          p1.second = now;
          p2.first = high + 1;
          p2.second = now;
          a[high + 1][now] += 1;
        } else {
          if (high == h - 1 and now == w - 1) {
            break;
          } else {
            p1.first = high;
            p1.second = now;
            p2.first = high;
            p2.second = now + 1;
            a[high][now + 1] += 1;
          }
        }
        ans.push_back(make_pair(p1,p2));
      }
    }
  };

  auto count_from_right = [&](int high) {
    for (int now = w - 1; now >= 0; --now) {
      pair<int,int> p1, p2;
      if (a[high][now] % 2) {
        if (now == 0 and high < h - 1) {
          p1.first = high;
          p1.second = now;
          p2.first = high + 1;
          p2.second = now; 

          a[high + 1][now] += 1;
        } else {
          p1.first = high;
          p1.second = now;
          p2.first = high;
          p2.second = now - 1;

          a[high][now - 1] += 1;
        }
        ans.push_back(make_pair(p1,p2));
      }
    }
  };

  rep(i, h) {
    if (i % 2) 
      count_from_right(i);
    else
      count_from_left(i);
  }
  ll cnt = 0;
  if (!ans.empty()) {
    cnt = ans.size();
      cout << cnt << endl;
  for (auto itr : ans) {
    pair<int,int> p1 = itr.first, p2 = itr.second;
    cout << p1.first+1 << " " << p1.second+1 << " " << p2.first+1 << " " << p2.second+1 << endl;
  }
  } else {
    cout << cnt << endl;
  }
  

}
