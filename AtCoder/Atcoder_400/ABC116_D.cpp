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

#define int long long 

void show_ans(ll ans) {
  cout << ans << endl;
}

signed main() {
  int n,k;
  cin >> n >> k;
  map<int, int> mp;
  // ネタの種類
  ll total = 0;
  vector<pair<int,int> > data;

  ll t,s;
  rep(i,n) {
    cin >> t >> s;
    // ネタのおいしさ、ネタの種類
    data.pb(make_pair(s,t));
    if (mp[t] == 0) total++;
    mp[t] += 1;
  }

  // ネタのおいしさで昇順にsort
  sorti(data);
  // どのネタを食べたかチェックするmap
  map<ll,ll> check;
  ll kd = 0, cnt = 0, itr = n-1, ans = 0;
  // ネタのおいしさを降順に
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > sushi;
  for (int i = n-1; i >= 0; --i) {
    ll various = data[i].second, value = data[i].first;
    cnt += 1;
    itr = i;
    ans += value;
    sushi.push(data[i]);
    if (check[various] == 0) kd++;
    check[various] += 1;
    
    if (cnt == k) break;
  }
  
  ll tmpans = ans;
  ans = ans + (kd * kd);
  if (itr == 0 or total == kd) {
    show_ans(ans);
    return 0;
  }

  for (int i = itr; i >= 0; --i) {
    if (sushi.size() == 0) break;
    ll various = data[i].second, value = data[i].first;
    if (check[various] > 0) continue;
    
    bool flag = false;
    while (sushi.size()) {
      pair<int,int> p = sushi.top();
      sushi.pop();
      if (check[p.second] > 1) {
        // ネタを1つ減らす
        check[p.second] -= 1;
        // おいしさを減らす
        tmpans -= p.first;
        break;
      } else {
        if (sushi.size() == 0) {
          flag = true;
        }
      }
    }

    if (flag) {
      break;
    }
    kd += 1;
    check[various] += 1;
    tmpans += value;
    ans = max(ans, tmpans + (kd * kd));
    if (kd == k) break;
  }

  show_ans(ans);
}
