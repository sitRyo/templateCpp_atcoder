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
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

ll solve(ll x) {
	string s = to_string(x);
	ll size = s.size();

	ll dp[100][2][2] = {};
	dp[0][0][0] = 1;

	rep(i, size) rep(j, 2) rep(k, 2) {
		// 10進数だから0 ~ 9, 0は未確定, 1は確定
		ll limit = j ? 9 : s[i] - '0';
		rep(d, x + 1) {
			dp[i + 1][j || d < x][k || d == 4 || d == 9] += dp[i][j][k];
		}
	}

	return dp[size][0][1] + dp[size][1][1];
}

int main() {
	ll a, b;
	cin >> a >> b;
	ll f1 = solve(a - 1);
	ll f2 = solve(b);

	
	cout << f2 - f1 << endl;
}
