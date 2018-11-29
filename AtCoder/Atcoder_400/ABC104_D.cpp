#include<iostream>
#include<cstdint>
using namespace std;

const int MOD = 1000000007; // 今回使う余り
const int MAX = 100001;
const int64_t MIN = 0;
int main() {
	string S;
	cin >> S;
	int l = S.size();
	static int64_t three[MAX], A[MAX], C[MAX], Q[MAX];
	A[0] = S[0] == 'A' ? 1 : 0;
	C[0] = S[0] == 'C' ? 1 : 0;
	Q[0] = S[0] == '?' ? 1 : 0;
	for (int i = 0;i < l;i ++) {
		A[i] = A[i - 1] + (S[i] == 'A' ? 1 : 0);
		C[i] = C[i - 1] + (S[i] == 'C' ? 1 : 0);
		Q[i] = Q[i - 1] + (S[i] == '?' ? 1 : 0);
	}
	three[0] = 1;
	for (int i = 1;i < l;i ++) {
		three[i] = three[i - 1] * 3 % MOD;
	}

	int64_t ans = 0;
  // l -> 文字列のサイズ
	for (int i = 1;i < l - 1; i++) {
		if (S[i] == 'B' || S[i] == '?') {
			ans += A[i] * (C[l - 1] - C[i]) % MOD * three[max(MIN, Q[l - 1] - (S[i] == '?' ? 1 : 0))] % MOD; // AとCを選ぶ場合 S[i]が'?'の場合 -1
			ans += Q[i - 1] * (C[l - 1] - C[i]) % MOD * three[max(MIN, Q[l - 1] - (S[i] == '?' ? 2 : 1))] % MOD; // ?とCを選ぶ場合
			ans += A[i] * (Q[l - 1] - Q[i]) % MOD * three[max(MIN, Q[l - 1] - (S[i] == '?' ? 2 : 1))] % MOD; // Aと?を選ぶ場合
			ans += Q[i - 1] * (Q[l - 1] - Q[i]) % MOD * three[max(MIN, Q[l - 1] - (S[i] == '?' ? 3 : 2))] % MOD; // ?と?を選ぶ場合
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
