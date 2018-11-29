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
typedef pair<ll, ll> P;

#define INF 10e10
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

ll N,M;
ll ans = 0;

std::vector<P> pr;

int main() {
  cin >> N >> M;

  REP(i,M) {
    P p;
    ll a,b;
    cin >> a >> b;
    p.first = a;
    p.second = b;
    pr.push_back(p);
  }

  sort(pr.begin(), pr.end());

  while(pr.size() > 0) {
    ll target = pr.back().first;
    for (vector<P>::reverse_iterator itr = pr.rbegin(); itr != pr.rend(); ++itr) {
      if (itr->second > target) {
        pr.erase(itr.base());
      }
    }
    ans++;
  }
  cout << ans << endl;
}
