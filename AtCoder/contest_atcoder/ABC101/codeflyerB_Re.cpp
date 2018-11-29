#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

vector<ll> x_sum;

ll f(ll a,ll b){
	if(a>b) return 0;
	ll res = x_sum[b];
	if(a>0) res -= x_sum[a-1];
	return res;
}

int main()
{
	ll n,q;
	cin >> n >> q;
	vector<ll> x(n);
	vector<pair<ll,ll> > p(q);

	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < q; i++){
		cin >> p[i].first >> p[i].second;
	}
	x_sum.resize(n);
	x_sum.assign(x_sum.size(),0);
	for(int i = 0; i < n; i++){
		x_sum[i] += x[i];
		if(i != 0) x_sum[i] += x_sum[i-1];
	}

	for(int i = 0; i < q; i++){
		int right = lower_bound(all(x),p[i].first+p[i].second) - x.begin();
		int left = lower_bound(all(x),p[i].first-p[i].second) - x.begin();

		int c = lower_bound(all(x),p[i].first) - x.begin();

		// cout << "right = " << right << " left = " << left << endl;
		// cout << "c =  " << c << endl;

		ll ans = 0;
		ans += (n-right + left) * p[i].second;

		//cout << "ans = " << ans << endl;

		ans += f(c,right-1) - p[i].first*(right - c);
		//cout << "ans = " << ans << endl;
		ans += -1*f(left,c-1) + p[i].first*(c - left);

		//cout << "c-1 ==" << c-1 << " left-1  = " << left -1<<endl;

		cout << ans << endl;
	}

	return 0;
}
