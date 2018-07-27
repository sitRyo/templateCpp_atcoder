#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

#define REP(i,n) for (int i=0; i<n; i++)

using namespace std;
typedef long long ll;

int main() {
  ll n,k;
  ll a[100005];
  ll pos;

  cin >> n >> k;
  REP(i,n){
    scanf("%lld", &a[i]);
    if (a[i] == 1) pos = i;
  }

  if (n==k){
    cout << 1 << endl;
    return 0;
  }

  ll left = 0,right = 0;
  ll ans = 0;
  left = pos;
  right = n - pos - 1;

  if (left < k && right < k) {
    cout << 2 << endl;
    return 0;
  }

  if (left < k) {
    pos = k-1;
    ans++;
    ans += (n - 1 - pos) / (k-1);
    if (((n-1-pos) % (k-1)) > 0) ans++;
  } else if (right < k) {
    pos = n - k;
    ans++;
    ans += pos / (k-1);
    if ((pos % (k-1)) > 0) ans++;
  } else {
    ans += left / (k-1);
    if ((left % (k-1)) > 0) ans++;
    ans += right / (k-1);
    if ((right % (k-1)) > 0) ans++;
  }
  cout << ans << endl;
}
