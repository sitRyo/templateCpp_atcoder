#include <iostream>

using namespace std;

int a, b;

int main() {
  cin >> a >> b;
  int relt = b - a;
  int total = 0;
  for (int i=1; i<relt; i++) {
    total += i;
  }

  cout << total - a;

}
