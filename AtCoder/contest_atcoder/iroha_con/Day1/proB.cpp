#include <iostream>
#include <string>

using namespace std;

int main() {
  int l;
  string s;
  cin >> s;
  cin >> l;
  
  l %= s.size();
  for (int i = l, num = 0; num < s.size(); (i = (i + 1) % s.size()), num++) {
    cout << s[i];
  }
  cout << endl;
}
