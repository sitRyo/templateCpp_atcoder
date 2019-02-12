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
  vector<ll> sushi[100001];
  vector<pair<ll,ll> > dt(n);
  map<ll,ll> mp;
  ll total = 0;
  rep(i,n) {
    ll tt,dd;
    cin >> tt >> dd;
    dt[i] = make_pair(dd, tt);
    if (mp[tt] == 0) total++;
    mp[tt] += 1;
  }

  sorti(dt);
  ll ans = 0, kd = 0, now = 0, countk = 0;
  map<int,int> check;
  vector<pair<ll,ll> > st;
  
  for (int i = n-1; i >= 0; --i) {
    ll various = dt[i].second, value = dt[i].first;
    // この寿司はもう食べたか？
    if (check[various] == 0) {
      // 食べてないなら
      check[various] += 1;
      kd++;
    }

    // おいしさ基礎ポイント
    ans += value;
    // 食べた寿司＋＋
    countk += 1;
    // mitakotoro
    now = i;
    // setに種類と数を入れる
    st.pb(make_pair(value, various));
    if (countk == k) break;
  }
  // cout << kd << " " << total << endl;
  // 食べた寿司の種類と食べた寿司の数が同じだったら
  if (kd == total) {
    cout << ans + (total * total) << endl;
    return 0;
  }
  sorti(st);
  // おいしさの合計
  ll tmpans = ans;
  ans += kd * kd;
  // 次は食べた寿司の種類を増やす
  int let = n-1;
  map<ll,bool> tt;
  
  for (auto itr : check) {
    if (itr.second == 1) tt[itr.first] = true;
  }
  
  for (int i = now; i >= 0; --i) {
    ll various = dt[i].second, value = dt[i].first;
    // 食べていた寿司の種類だったらスルー
    if (check[various]) continue;
    if (let == n) {
      break;
    }
    kd += 1;
    while (let < n) {
      ll various2 = st[let].second, value2 = st[let].first;
      let -= 1;
      if (tt[various2]) continue;

      tmpans -= value2;
      check[various] -= 1;
      if (check[various] == 1) tt[various] = true;
    }
    
    tmpans += value;
    check[various] = true;
    ans = max(ans, (tmpans + (kd * kd)));
    // 食べた寿司が全ての種類1つずつだったら出る
    if (kd == k) {
      ans = ans + (kd * kd);
      break;
    }
  }

  cout << ans << endl;
}
