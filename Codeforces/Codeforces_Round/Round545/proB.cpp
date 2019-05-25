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
  int numc = 0, numa = 0;
  cin >> n;
  string s1,s2;

  cin >> s1 >> s2;

  vector<int> p(n+1);
  map<int,int> mp;
  for (int i = 0; i < n; ++i) {
    if (s1[i] == '1' and s2[i] == '1') p[i] = 1;
    else if (s1[i] == '0' and s2[i] == '1') p[i] = 3;
    else if (s1[i] == '1' and s2[i] == '0') p[i] = 2;
    else p[i] = 4;
    mp[p[i]] += 1;
    if (s2[i] == '1') numa += 1;
  }
  
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    // cout << p[i] << endl;
    if (numa > numc) {
      switch (p[i]) {
        case 1: {
          if (numa - numc > 1) {
            ans.push_back(i+1);
            numa -= 1;
            numc += 1;
          }
          mp[1] -= 1;
          break;
        }

        case 2: {
          ans.push_back(i+1);
          numc += 1;
          mp[2] -= 1;
          break;
        }

        case 3: {
          ans.push_back(i+1);
          numa -= 1;
          mp[3] -= 1;
          break;
        }
      }
    } else if (numa == numc and ans.size() < n / 2 and p[i] == 4) {
      ans.push_back(i+1);
    }
  }

  if (numa == numc and ans.size() == n / 2) {
    for (auto itr : ans) cout << itr << " ";
    END;
    return 0;
  }

  cout << -1 << endl;
}
