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

/* add vars here */

string str;

/* add your algorithm here */

int main() {
  cin >> str;

  stack<char> st;
  for (int i = 0; i < str.size(); ++i) {
    if (st.size() == 0) {
      st.push(str[i]);
      continue;
    }
    if (st.top() == 'S') {
      if (str[i] == 'T') {
        st.pop();
      } else {
        st.push(str[i]);
      }
    } else if (st.top() == 'T') {
      st.push(str[i]);
    }
  }

  cout << st.size() << endl;
}
