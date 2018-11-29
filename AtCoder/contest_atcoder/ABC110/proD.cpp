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
#define MAX 100
#define MOD 1000000007
#define pb push_back
#define END cout << endl

/* add vars here */

ll n,m;

/* add your algorithm here */

std::vector<ll> enum_div(ll n)//nの約数を列挙
{
	std::vector<ll> ret;
	for(int i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i!=1 && i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}

int calcNumOfCombination(int n, int r){
    int num = 1;
    for(int i = 1; i <= r; i++){
        num = num * (n - i + 1) / i;
    }
    return num;
}

int main() {
  cin >> n >> m;
  vector<ll> r = enum_div(n);
  r.pb(n);

  ll s = r.size();
  ll mo = n - 1;
  ll ans = 0;

  if (n >= s + 1) ans = s / 2;
  else if (n == s) {
    ans = s + 1;
  } else {
    
  }
}
