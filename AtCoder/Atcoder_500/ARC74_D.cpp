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

int main() {
  int n,len;
  vector<ll> a, sum;
  
  cin >> n;
  a = vector<ll>(n);
  sum = vector<ll>(n);
  len = 3 * n;

  rep(i,len) {
    cin >> a[i];
  }

  priority_queue<ll> preque, befque; // 昇順
  priority_queue<ll, vector<ll>, greater<ll> > preque_dec, befque_dec;
  vector<ll> t(n),s(n);
  ll presum = 0, befsum = 0;
  ll premax = 0, befmax = 0;

  rep(i,n) {
    presum += a[i];
    preque.push(a[i]);
    preque_dec.push(a[i]);
  }

  premax = presum;
  for (int k = n; k <= 2*n; ++k) {
    int presize = k - n;
    int itr = presum;

    if (presize > 0) {
      preque.push(a[k-1]);
      itr += a[k-1];
      preque.pop();
      
      preque_dec.push(a[k-1]);
      itr -= preque_dec.top();
      preque_dec.pop();
    }
    presum = itr;
    t[k - n] = itr;
  }

  rep(i,n) {
    befsum += a[len - i - 1];
    befque.push(a[len - i - 1]);
    befque_dec.push(a[len - i - 1]);
  }

  for (int k = n; k <= 2*n; ++k) {
    int befsize = k - n;
    int itr = befsum;

    if (befsize > 0) {
      
    }
  }
}
