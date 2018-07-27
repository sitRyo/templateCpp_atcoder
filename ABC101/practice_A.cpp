#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  int ans = 0;
  cin >> str;

  for (int i=0; i<4; i++) {
    if (str[i] == '+') ans++;
    else ans--;
  }
  cout << ans << endl;
}
