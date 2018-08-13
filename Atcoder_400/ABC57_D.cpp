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

#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

// comb_table
ll C[51][51];

/* add your algorithm here */

void comb_table (int N) {
  rep(i,N+1) {
    rep(j,i+1) {
      if (j == 0 || j == i)
      C[i][j] = 1;
      else
      C[i][j] = (C[i-1][j-1] + C[i-1][j]); // 二項定理
    }
  }
}

int main() {
  int N,A,B;
  cin >> N >> A >> B;

  const int NMAX = 50;
  ll v[NMAX];

  rep(i,N) cin >> v[i];

  comb_table(N);
  sort(v,v+N);
  reverse(v,v+N);

  double max_average = 0.0;
  rep(i,A) max_average += v[i];
  max_average /= A;

  int a_th_val_num = 0, a_th_val_pos = 0;
  rep(i,N) {
    if (v[i] == v[A-1]) {
      a_th_val_num++;
      if (i < A) {
        a_th_val_pos++;
      }
    }
  }

  cout << a_th_val_num << endl;
  cout << a_th_val_pos << endl;

  ll cnt = 0LL;
  if (a_th_val_pos == A) {
    for (a_th_val_pos = A; a_th_val_pos <= B; ++a_th_val_pos) {
      cnt += C[a_th_val_num][a_th_val_pos];
    }
  } else {
    cnt += C[a_th_val_num][a_th_val_pos];
  }

  cout.precision(20);
  cout << fixed << max_average << endl;
  cout << cnt << endl;
}
