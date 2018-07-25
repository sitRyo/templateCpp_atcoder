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
typedef map<ll, bool> lmap;

#define INF 10e10
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

ll N;
lmap lmp;
ll ans = 0LL;

int main() {
  cin >> N;

  ll target;
  ll ans = 0;
  REP(i,N) {
    scanf("%lld", &target);
    if (lmp[target]) {
      lmp[target] = false;
      ans--;
    } else {
      lmp[target] = true;
      ans++;
    }
  }

  cout << ans << endl;
}
