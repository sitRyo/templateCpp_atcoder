#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define REP(i,n) for (int i=0; i<n; i++)

int main() {
  int d,n;
  cin >> d >> n;

  long long ans = 1LL;
  long long a = 1LL;
  REP(i,d) a*=100;
  cout << a * n << endl;
}
