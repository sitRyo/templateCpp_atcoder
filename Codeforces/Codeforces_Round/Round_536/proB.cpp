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
  int n,m; // n: food, m: customers
  priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
  cin >> n >> m;
  bool flag = true;
  vector<ll> a(n),c(n);
  vector<pair<ll,ll> > pa(n);
  rep(i,n) {
    scanf("%lld", &a[i]);
  }
  rep(i,n) {
    scanf("%lld", &c[i]);
  }

  rep(i,n) {
    pq.push(make_pair(c[i], i));
  }


  int itr = 0; // cheapest itrator
  for (int i = 0; i < m; ++i) {
    ll d,t;
    ll ans = 0;
    scanf("%lld %lld", &d,&t);
    d--;

    if (a[d] > 0) {
      ll cpy = t;
      if (t > a[d]) {
        ans += a[d] * c[d];
        t -= a[d];
        a[d] = 0;
      } else {
        a[d] -= t;
        t = 0;
        ans += cpy * c[d];
      }
    }
    // cout << "*****" << endl;
    // cout << "t:" << t << " ans: " << ans << endl;
    while (t > 0 and !pq.empty()) {
      pair<ll,ll> p = pq.top();
      ll value = p.first, various = p.second, cpy = t;
      /*
      if (various == d) {
        break;
      }*/

      ll remain = a[various];

      if (remain > t) {
        a[various] -= t;
        t = 0;
        ans += cpy * value;
      } else {
        a[various] = 0;
        ans += remain * value;
        t -= remain;
        pq.pop();
      }
    }

    if (t > 0) flag = false;

    if (flag)
      cout << ans << endl;
    else 
      cout << 0 << endl;
  }
}
