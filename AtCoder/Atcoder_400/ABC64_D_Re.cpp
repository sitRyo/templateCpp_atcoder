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
#include <stack>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back

int main() {
  int n;
  string s;

  cin >> n;
  cin >> s;

  stack<char> st;
  int rb = 0, lb = 0;

  for (auto itr : s) {
    if (itr == ')') rb++;
    else lb++;

    if (st.empty()) {
      st.push(itr);
      continue;
    }

    if (itr == ')' && st.top() == '(') {
      lb--, rb--;
      st.pop();
    } else {
      st.push(itr);
    }
  }

  rep(i,rb) {
    cout << '(';
  }

  cout << s;

  rep(i,lb) {
    cout << ')';
  }

  cout << endl;
}
