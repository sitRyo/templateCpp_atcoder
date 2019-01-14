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
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

 
ll a[200050] = {};
ll A[200050] = {};
 
int main()
{
	ll n;
	ll ans = 0;
	cin >> n;
  vector<ll> a(n), A(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		A[i] = a[i];
	}
 
	sort(a.begin(), a.end());
	ll b;
	if (n % 2 != 0) {
		b = a[(n - 1) / 2];
	}
	else {
		b = (a[n / 2] + a[(n / 2) - 1]) / 2;
	}
 
	b = b - (n - 1) / 2;
 
	for (ll i = 0; i < n; i++)
	{
		ans += abs(A[i] - b);
		b++;
	}
 
	cout << ans << endl;
}