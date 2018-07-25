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
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define SMAX 50

string miss_match = "UNRESTORABLE";

int main() {
  string S, T;

  cin >> S;
  cin >> T;

  if (T.size() > S.size()) {
    cout << miss_match << endl;
    return 0;
  }

  int pos = 100;

  // 高々, ( |S| - |T| + 1 ) 通り
  // 候補を全て考える. 候補が複数ある場合, できるだけ後ろのものを採用.
  REP(cand, S.size() - T.size() + 1) {
    int count = 0;
    for (int index = cand; index < cand + T.size(); index++) {

      if (S[index] != '?' && S[index] != T[count]) {
        break;
      }
      count++;
      if (count == T.size()) {
        pos = cand;
      }

    }

  }

  if (pos == 100) {
    cout << miss_match << endl;
  } else {

    int j = 0;


    // pos以降を文字列Tで埋める
    for (int i = pos; i < pos + T.size(); i++) {
      S[i] = T[j];
      ++j;
    }


    // '?'を'a'で埋める
    REP(i,S.size()) {
      if (S[i] == '?') S[i] = 'a';
    }

    cout << S << endl;
  }

  return 0;
}
