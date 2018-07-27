#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;

  int ten = 10;
  int x = n;
  int a;
  int sum = 0;
  while (x > 0) {
    a = x % ten;
    sum += a;
    x /= 10;
  }
  if (!(n%sum)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
