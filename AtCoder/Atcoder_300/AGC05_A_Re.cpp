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

stack<char> st;

int main() {
  string s;
  cin >> s;

  for (auto itr : s) {
    if (st.size() == 0) {
      st.push(itr);
    } else {
      if (itr == 'T' && st.top() == 'S') {
        st.pop();
      } else {
        st.push(itr);
      }
    }
  }

  cout << st.size() << endl;
}
