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
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  string s;
  cin >> s;

  stack<char> st;
  vector<char> ans;
  char trans;
  for (auto ch : s) {
    if (ch == '+' or ch == '-' or ch == '*' or ch == '/') {
      st.push(ch);
    } else

    if (ch == ')') {
      ans.pb(ch);
      st.pop();
    } else

    if (ch == ',') {
      ans.pb(st.top());
    } else {
      // others
      ans.pb(ch);
    }
  }

  for (auto itr : ans) {
    cout << itr;
  } END;
}
