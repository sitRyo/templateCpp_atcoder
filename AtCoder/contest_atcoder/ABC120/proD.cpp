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
#include <map>
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

vector<int> edge[100002];
int visited[100002], wei[100002];
map<pair<int,int>, bool> mp;


int dfs(int now) {
  visited[now] = true;
  for (auto itr : edge[now]) {
    if (!visited[itr]) {
      wei[now] += dfs(itr);
      mp[make_pair(itr,now)] = true;
      mp[make_pair(now,itr)] = true;
    }
  }

  return wei[now] + 1;
}


int main() {
  ll ans = 0;
  
  int n,m;
  cin >> n >> m;

  vector<pair<int,int> > data(m);

  rep(i,m) {
    ll k,j;
    cin >> k >> j;

    edge[k].push_back(j);
    edge[j].push_back(k);

    data[i] = make_pair(j,k);
  }


  dfs(1);

  for (auto itr : data) {
    if (!mp[itr]) {
      
    }
  }
}
