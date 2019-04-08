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

// s[j] == 'A' or s[j] == 'C' or s[j] == 'G' or s[j] == 'T'

int main() {
  int n,q;
  cin >> n >> q;

  string s;
  cin >> s;

  vector<int> sum(n+1);
  sum[0] = 0;


  for (int i = 1; i < n; ++i) {
    if (s[i-1] == 'A' and s[i] == 'C') {
      sum[i+1] += sum[i] + 1;
    } else {
      sum[i+1] = sum[i];
    }
  }
  /*
  for (auto itr : sum) cout << itr << " ";
  END;*/

  for (int i = 0; i < q; ++i) {
    int l,r; 
    cin >> l >> r;
    cout << sum[r] - sum[l] << endl;
  }
}
