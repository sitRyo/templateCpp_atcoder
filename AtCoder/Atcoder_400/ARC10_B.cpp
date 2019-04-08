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

int main() {
  int n;
  cin >> n;
  vector<int> date[12];
  
  rep(i,n) {
    int a,b;
    scanf("%d%*c%d", &a, &b);
    date[a-1].push_back(b);
  }

  rep(i,12) sorti(date[i]);

  for (int i = 0; i < 12; ++i) {
    int month = i + 1;
    // 0 ~ 6 (sun - st)
    int now = 0; 
    if (month == 2) {
      rep(i,29) {
        if (now == 6) {
          date[i].push_back(1);
        } else if (now == 0) {
          date[i].push_back(2);
        } else {
          date[i].push_back(0);
        }
        now = (now + 1) % 7;
      }
    } else if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8
    or month == 10 or month == 12) {
      rep(i,31) {
        if (now == 6) {
          date[i].push_back(1);
        } else if (now == 0) {
          date[i].push_back(2);
        } else {
          date[i].push_back(0);
        }
        now = (now + 1) % 7;
      }
    } else {
      rep(i,30) {
        if (now == 6) {
          date[i].push_back(1);
        } else if (now == 0) {
          date[i].push_back(2);
        } else {
          date[i].push_back(0);
        }
        now = (now + 1) % 7;
      }
    }
  }
  
  for (int i = 0; i < n; ++i) {
    int day = d[i] - 1;
    int month = m[i] - 1;
    
    if (date[month][day] == 2) {
      while (true) {
        
      }
    }
    
  }
}
