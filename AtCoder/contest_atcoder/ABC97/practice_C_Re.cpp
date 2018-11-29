#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define REP(i,n) for (int i=0; i<N; i++)

int K;
string str;
char s[5005];
char a[26] = {
  'a','b','c','d','e','f','g',
  'h','i','j','k','l','m','n',
  'o','p','q','r','s','t','u',
  'v','w','x','y','z'
};

int main() {
  scanf("%s", s);
  scanf("%d", &K);

  str = string(s);
  int size = str.size();
  int count = 0;
  for (int i=0; i<26; i++) {
    int temp = count;
    std::vector<string> v;
    string::size_type pos = str.find(a[i]);
    while(pos != string::npos) {
      string builder = string();
      for (int j=pos; j<size; j++) {
        builder += str[j];
        v.push_back(builder);
      }
      pos = str.find(a[i], pos+1);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    count += size;
    if (K <= count) {
      int target = K - temp - 1;
      cout << v[target] << endl;
      break;
    }
  }

  return 0;

}
