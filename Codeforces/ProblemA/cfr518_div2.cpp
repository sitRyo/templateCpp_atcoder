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

/*
N個違うコインがあって，IvanはそのうちのK個を持っている
M人の友達が彼にコインを贈ることに決めた
1，M人全員は同じ数のコインを贈る
2，全てのコインはIvanのものと違っている必要がある
3，贈るコインの合計はL以上で，Ivanの持っているコインと違っている必要がある
友達はIvanの持っているコインを知らない

最小が1枚 * m => tm;
tm < l なら tm / l + (tm % l > 0) ? 1 : 0;
  * tm > n で -1
tm > k ならOK
tm <= kなら
tm - k => tk;
tk / m + (tk % m > 0) ? 1 : 0;
  * tk + tm > n で -1


*/

int main() {
  ll n,m,k,l;
  cin >> n >> m >> k >> l;

  if (m > n) {
    cout << -1 << endl;
    return 0;
  }

  if (!((n - k) / m)){
    cout << -1 << endl;
    return 0;
  }

  ll tm = m, ans = 1;
  if (tm < l) {
    int t = (tm % l > 0) ? 1 : 0;
    ll tmp = tm;
    tm += (l / tm) * m + t * m;
    ans += l / tmp + t;
  }

  if (tm > n) {
    cout << -1 << endl;
    return 0;
  }

  if (tm > k) {
    cout << ans << endl;
  } else if (tm <= k) {
    ll tk = tm - k, t;
    t = (tk % m > 0) ? 1 : 0;
    tk += (tk / m) * m + t * m;
    ans += tk / m + k;

    if (tk + tm > n) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
