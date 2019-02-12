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
#include <set>
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
  int n,k;
  cin >> n >> k;
  if (n == k) {
    cout << " " << endl;
    return 0;
  }
  set<int> ok;
  vector<string> s(n);
  rep(i,k) {
    int tmp;
    cin >> tmp;
    ok.insert(tmp-1);
  }
  rep(i,n) cin >> s[i];
  string keyword = s[*(ok.begin())];
  int key_length = (int)keyword.length();

  for (int i : ok) {
    int common_length = 0;
    while (common_length < min(key_length, (int)s[i].length())) {
      if (keyword[common_length] == s[i][common_length]) {
        common_length++;
      } else {
        break;
      }
    }

    keyword = keyword.substr(0,common_length);
    key_length = (int)keyword.length();
  }

  vector<int> ng_length;
  rep(i,n) {
    if (ok.find(i) != ok.end()) continue;
    int common_length = 0;
    while (common_length < min(key_length, (int)s[i].length())) {
      if (keyword[common_length] == s[i][common_length]) {
        common_length++;
      } else {
        break;
      }
    }
    ng_length.pb(common_length);
  }

  int ans_length = *max_element(ng_length.begin(), ng_length.end()) + 1;
  if (ans_length <= key_length) {
    cout << keyword.substr(0,ans_length) << endl;
  } else {
    cout << -1 << endl;
  }
}
