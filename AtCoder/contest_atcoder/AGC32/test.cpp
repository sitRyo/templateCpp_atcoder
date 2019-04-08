#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int,int> mp;
  mp[3] = 1;
  mp[4] = 1;
  mp[5] = 1;

  for (auto itr : mp) {
    cout << itr.first << " " << itr.second << endl;
  }
}