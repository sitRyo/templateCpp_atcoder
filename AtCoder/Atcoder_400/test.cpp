#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main() {
  vector<string> s(3);
  for (int i = 0; i < 3; ++i) {
    string t;
    cin >> t;
    s[i] = t;
  }
/*
  cout << s[0].size() << endl;
  cout << s[1].size() << endl;
  cout << s[2].size() << endl;
*/
  char t = 'a';
  
  vector<int> cnt(3,0);
  while (true) {
    int c = t - 'a';
	  int target = cnt[c];
    if (target >= s[c].size()) {
      cout << (char)toupper(t) << endl;
      return 0;
    }
    char tt = s[c][target];
    cnt[c] += 1;
    t = tt;
  }
}
