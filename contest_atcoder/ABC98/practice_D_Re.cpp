#include <cstdio>
#define REP(i,n) for(int i=0; i<n; i++)

long long n;
long long s[1048577];
long long right=0, left=0;
long long ans = 0;
long long sum=0, xr=0;

int main() {
  scanf("%lld",&n);
  REP(i,n) scanf("%lld", &s[i]);

  for(left=0; left<n; left++) {
    while (right < n && ((sum+s[right]) == (xr^s[right]))) {
      sum += s[right];
      xr ^= s[right];
      right++;
    }
    ans += right - left;
    if (left == right){
      right++;
    } else {
      sum -= s[left];
      xr ^= s[left];
    }
  }
  printf("%lld",ans);
}
