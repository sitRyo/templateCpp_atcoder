#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  std::vector<string> v = {
    "abc", "aabc", "abcd", "abc", "acd"
  };

  sort(v.begin(),v.end());
  cout << "--------------------" << endl;
  for (auto itr = v.begin(); itr != v.end(); itr++) {
    cout << *itr << endl;
  }
  cout << "--------------------" << endl;
  cout << "--------------------" << endl;
  v.erase(unique(v.begin(), v.end()), v.end());
  for (auto itr = v.begin(); itr != v.end(); itr++) {
    cout << *itr << endl;
  }
  cout << "--------------------" << endl;
}
