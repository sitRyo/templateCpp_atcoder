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
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n,m;
  cin >> n >> m;
  vector<pair<int, ll>> yp;
  vector<int> data;


  rep(i,m) {
    ll t,s; cin >> t >> s;
    pair<int,ll> p = make_pair(s,i);
    yp.pb(p);
    data.pb(t);
  }

  sorti(yp);

  vector<int> sum(n+1,1);
  vector<pair<int,string>> ans;

  for (auto itr : yp) {
    int a,index;
    index = itr.second;

    // a:ken, t: junnbann
    a = data[index];
    int t = sum[a];
    sum[a]++;

    string str = "000000";
    string str1, str2;
    str1 = str + to_string(a);
    str2 = str + to_string(t);

    str1 = str1.substr(str1.size()-6,str1.size()-1);
    str2 = str2.substr(str2.size()-6,str2.size()-1);
    // string res = str1 + str2;

    ans.pb({index,str1+str2});
  }

  sorti(ans);

  for (auto itr : ans) {
    cout << itr.second << endl;
  }
}
