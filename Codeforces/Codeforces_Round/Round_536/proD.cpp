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

vector<int> graph[100001];
vector<int> ans;
bool visit[100001];
int n,m;
set<int> st;

int main() {
  cin >> n >> m;
  rep(i,m) {
    ll x,y;
    scanf("%lld %lld", &x, &y);
    graph[x].pb(y);
    graph[y].pb(x);
    st.insert(x);
    st.insert(y);
  }

  int start = *(st.begin());

  priority_queue<int, vector<int>, greater<int> > que;
  visit[start] = true;
  cout << start << " ";
  for (int itr : graph[start]) {
    que.push(itr);
  }
  int cnt = 0;
  while (que.size()) {
    priority_queue<int, vector<int>, greater<int> > next_level_queue;
    while (que.size()) {
      int target = que.top();
      que.pop();
      if (!visit[target]) {
        cout << target << " ";
        visit[target] = true;
        for (auto itr : graph[target]) {
          next_level_queue.push(itr);
        } 
      }
    }
    que = next_level_queue;
  }
  // cout << cnt << endl;
  END;
}
