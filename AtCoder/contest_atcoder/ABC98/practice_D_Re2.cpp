

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1e9
#define PI acos(-1)
typedef long long ll;


int main() {

	int n; cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++)cin >> a[i];

	ll sum = 0, xr=0, ans = 0;
	int right = 0;

	for (int left = 0; left < n; left++) {
		while (right < n&&((sum + a[right]) == (xr^a[right]))) {
			sum += a[right];
			xr ^= a[right];
			right++;
		}

		ans += (right - left);

		if (right == left)right++;
		else {
			sum -= a[left];
			xr ^= a[left];
		}

	}

	cout << ans << endl;

	return 0;
}
