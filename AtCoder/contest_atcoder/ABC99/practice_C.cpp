#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long N;

int slove(long N) {
  std::vector<int> v;
  int total = N;
  int i = 9;
  int relt = 0;

  while (i <= 100000) {
    v.push_back(i);
    i *= 9;
  }
  i = 6;
  while (i <= 100000) {
    v.push_back(i);
    i *= 6;
  }

  sort(v.begin(), v.end(), std::greater<int>());

  for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++) {
    while (total >= *itr) {
      cout << "total: " << total << " " << "target: " << *itr << endl;
      total -= *itr;
      relt++;
    }
  }

  relt += total;
  return relt;
}

int main() {
  cin >> N;
  cout << slove(N) << endl;
}
