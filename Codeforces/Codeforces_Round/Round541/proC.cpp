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
  cin >> n;
  vector<ll> a(n);
  map<ll,ll> mp;
  rep(i,n) {
    cin >> a[i];
    mp[a[i]] += 1;
  }

  sorti(a);
  bool flag1 = true, flag2 = true;
  
  deque<ll> dq;
  for (int i = n-1; i >= 0; --i) {
    if (i % 2 == 0) {
      dq.push_front(a[i]);
    } else {
      dq.push_back(a[i]);
    }
  }

  for (auto itr : dq) {
    cout << itr << " ";
  }

  END;
}
