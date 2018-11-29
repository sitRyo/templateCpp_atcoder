#include <cstdio>
#include <string>

using namespace std;

string str;
char s[5001];
char a[26] = {
  'a','b','c','d','e','f','g',
  'h','i','j','k','l','m','n',
  'o','p','q','r','s','t','u',
  'v','w','x','y','z'
};
int K;
int size;

int main() {
  scanf("%s", s);
  scanf("%d", &K);

  str = string(s);
  size = str.size();
  int count = 0;
  int position[5001];
  for (int i=0; i<26; i++) {
    string::size_type pos = str.find(a[i]);
    int j = 0;
    while (pos != string::npos) {
      position[j] = pos;
      pos = str.find(a[i], pos+1);
      j++;
    }
    for (int k=0; k<j; k++) {
      for (int l=0; l<k; l++) {

      }
    }
  }
}
