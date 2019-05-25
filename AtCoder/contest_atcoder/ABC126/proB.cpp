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
  string s;
  cin >> s;

  string s1 = s.substr(0, 2);
  string s2 = s.substr(2);

  if (s1 == "00") {
    if (s2 <= "12" and s2 != "00") {
      cout << "YYMM" << endl;
    } else {
      cout << "NA" << endl;
    }
    return 0;
  }
  if (s1 <= "12") {
    if (s2 <= "12" and s2 != "00") {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "MMYY" << endl;
    }
  } else {
    if (s2 <= "12" and s2 != "00") {
      cout << "YYMM" << endl;
    } else {
      cout << "NA" << endl;
    }
  }
}
