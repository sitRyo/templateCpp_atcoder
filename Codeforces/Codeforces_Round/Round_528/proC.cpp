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

int main()
{
	int i,ans;
	int x[4];
	int y[4];
	map<int,int> m;
	for(i=1;i<=3;i++)
	{
		cin>>x[i]>>y[i];
		m[x[i]]=y[i];
	}
	sort(x+1,x+4);
	sort(y+1,y+4);
	ans=x[3]-x[1]+y[3]-y[1]+1;
	cout << ans << endl;
	for(i = x[1]; i < x[2]; i++)
		cout << i << " " << m[x[1]] << endl;
	for(i = x[3]; i > x[2]; i--)
		cout << i << " " << m[x[3]] << endl;
	for(i = y[1]; i <= y[3]; i++)
		cout << x[2] << " " << i << endl;
}