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

int n,g,e;
vector<int> E[102];
vector<int> p(102), visited(102, 0);

int dfs(int x) {
  visited[x] = true;
  
}

int main() {
  cin >> n >> g >> e;
  rep(i,g) cin >> p[i];
  rep(i,e) {
    int a,b;
    cin >> a >> b;
    E[b].push_back(a);
    E[a].push_back(b);
  }


}
