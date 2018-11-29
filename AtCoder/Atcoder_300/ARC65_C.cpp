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

string s;
string t = "";

int main() {
  cin >> s;

  for (int i = s.size() - 1; i >= 0; --i) {
    t += s[i];
    if (t.size() >= 5 && t.size() <=7) {
      string temp = t;
      for (int j = 0; j < t.size() / 2; ++j) {
        swap(temp[j], temp[t.size() - 1 - j]);
      }
      if (temp == "dream") {
        t = "";
      } else if (temp == "dreamer") {
        t = "";
      } else if (temp == "erase") {
        t = "";
      } else if (temp == "eraser") {
        t = "";
      }
    }
  }

  if (t.empty()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
