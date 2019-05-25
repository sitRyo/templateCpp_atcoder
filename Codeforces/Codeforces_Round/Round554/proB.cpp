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
#include <bitset>
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
  ll x;
  cin >> x;

  int digit = 0;
  ll cpy = x;
  while (cpy > 0) {
    cpy /= 2;
    digit += 1;
  }

  vector<ll> two;
  ll t = 1;
  while (t < 1000000) {
    two.push_back(t);
    t *= 2;
  }

  bool flagg = true;

  for (int i = 0; i < digit; ++i) {
    bool bit = (x >> i) & 1;
    if (!bit) {
      flagg = false;
      break;
    }
  }

  if (flagg) {
    cout << 0 << endl;
    return 0;
  }
  
  vector<int> ans;
  while (true) {
    bool flag = false;
    vector<bool> vec(digit, 0);

    for (int i = digit - 1; i >= 0; --i) {
      bool bit = (x >> i) & 1;
      // debug(bit);
      if (flag) {
        vec[i] = true;
      } else {
        if (bit) {
          vec[i] = false;
        } else {
          vec[i] = true;
          flag = true;
          ans.push_back(i + 1);
        }
      }
    }
    
    ll tmp = 0;
    for (int i = 0; i < digit; ++i) {
      int bit1 = (x >> i) & 1, bit2 = vec[i];
      // cerr << bit1 << " " << bit2 << endl;
      if (bit1 != bit2) {
        tmp += two[i];
      }
    }
    
    x = tmp;
    x += 1;

    bool judge = true;
    for (int i = 0; i < digit; ++i) {
      int bit = (x >> i) & 1;
      if (!bit) {
        judge = false;
        break;
      }
    }
    
    if (judge) {
      break;
    }
  }

  cout << ans.size() * 2 << endl;
  for (auto itr : ans) {
    cout << itr << " ";
  }
  END;
}
