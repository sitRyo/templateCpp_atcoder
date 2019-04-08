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

// dp[i] := ちょうどi本のマッチ棒を使って、条件を満たす整数を作るときの最大桁数
// dp[N] := ちょうどN本のマッチ棒を使って作ることができる最大桁数 <- これが答え！
// 整数kを1桁作るのに使うマッチ棒の本数をnum(k)とすると、Aiを最上位の桁に使えることを調べるには、
// dp[N-num(Ai)] = dp[N] - 1
// dp[i] = max(0 < j < m)(dp[i-num(Aj)] + 1)
// どっちを参照する? dp[i + match(a-1)] or dp[i] + (char)('0' + a)) !!
// dp[i + match(a-1)] はすでに以前に更新されている可能性がある。

const string MINUSINF = "-";

void chmax(string &a, string b) {
  if (a == MINUSINF) a = b;
  else if (a.size() < b.size()) a = b;
  else if (a.size() == b.size()) {
    if (a < b) a = b;
  }
}

ll match[10] = {2,5,5,4,5,6,3,7,6};
string dp[11000];

int main() {
  int N,M; cin >> N >> M;
  vector<int> A(M);
  rep(i,M) cin >> A[i];

  rep(i,11000) dp[i] = MINUSINF;

  dp[0] = "";

  rep(i,N) {
    if (dp[i] == MINUSINF) continue;
    for (auto a : A) chmax(dp[i+match[a-1]], dp[i] + (char)('0' + a));
  }
  cout << dp[N] << endl;
}
