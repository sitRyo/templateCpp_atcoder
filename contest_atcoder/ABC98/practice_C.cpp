#include <cstdio>

#define REP(i,n) for (int i=0; i<n; i++)
#define MIN(x,y) x < y ? x : y
const int MAXN = 300005;

int n, e[MAXN], ans = 1 << 30;
char s[MAXN];

int main() {
  scanf("%d", &n), scanf("%s", s);
  REP(i,n) e[i+1] = e[i] + (s[i] == 'E');
  REP(i,n) ans = MIN(ans, i - e[i] + e[n] - e[i+1]);
  printf("%d", ans);
  return 0;
}
