#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const int MAX_DIGIT = 50;
long long dp[100][2]; // dp[上から i 桁まで][ smaller ]

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  
  memset(dp, -1, sizeof(dp)); // DP 配列を -1 で初期化
  dp[0][0] = 0; // 初期条件
  for (int d = 0; d < MAX_DIGIT; ++d) {
    long long mask = 1LL<<(MAX_DIGIT - d - 1);
  
    // A で元々 d 桁目にビットが立っているものの個数
    int num = 0;
    for (int i = 0; i < N; ++i) if (A[i] & mask) ++num;
     
    // X の d 桁目を 0, 1 にしたときのコスト
    long long cost0 = mask * num;
    long long cost1 = mask * (N - num);
        
    // smaller -> smaller
    if (dp[d][1] != -1) {
      chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1)); // 0 でも 1 でも自在に大きい方
    }
        
    // exact -> smaller
    if (dp[d][0] != -1) {
      if (K & mask) { // K の d 桁目が 1 だったら、X の d 桁目は 0 にする
        chmax(dp[d+1][1], dp[d][0] + cost0);
      }
    }
        
    // exact -> exact (K にぴったり合わせる)
    if (dp[d][0] != -1) {
      if (K & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
      else chmax(dp[d+1][0], dp[d][0] + cost0);
    }
  }
  cout << max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]) << endl;
}
