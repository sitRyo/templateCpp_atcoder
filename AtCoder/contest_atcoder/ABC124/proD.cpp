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
typedef pair<int, int> pi;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  ll n,k;
  cin >> n >> k;

  string s;
  cin >> s;

  bool f = true;
  for (auto itr : s) {
    if (itr == '0') {
      f = false;
      break;
    }
  }

  if (f) {
    cout << n << endl;
    return 0;
  }

  vector< pi > v;
  bool flag = true;
  vector<int> ku, en;
  ll cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' and flag) {
      ku.push_back(i+1);
      flag = false;
    } else if (s[i] == '1' and !flag) {
      en.push_back(i);
      flag = true;
      cnt += 1;
    }
  }

  if (!flag) {
    en.push_back(n);
    cnt += 1;
  } else {
    en.back() = n;
  }
  /*
  for (int i = 0; i < en.size(); ++i) {
    cout << ku[i] << " " << en[i] << endl;
  }*/
  // cout << ku.size() << endl;
  ll now = 0, nex = 0, ans = 1;

  if (k == 1 and ku.size() == 1) {
    cout << n << endl;
    return 0;
  }

  for (int i = 0; i < ku.size() - k + 1; ++i) {
    nex = en[k + i - 1];
    if (k == 1) {
      nex = ku[k + i] - 1;
    }
    ans = max(ans, nex - now);
    now = en[i];
    if (k == 1) {
      now = en[i];
    }
  }

  cout << ans << endl;
}
