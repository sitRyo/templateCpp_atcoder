#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define REP(i,n) for (int i=0; i<N; i++)

int main() {
  int a,b;
  scanf("%d%d", &a,&b);
  if (a<=8 && b<=8) printf("Yay!");
  else printf(":(");
}
