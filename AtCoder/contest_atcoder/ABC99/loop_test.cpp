#include<cstdio>
#include<iostream>
#include<ctime>

#define N 100000000
#define REP(i,N) for(int i=0; i<N; i++)

int D;

using namespace std;

int main() {
  printf("通常のforループ ");
  clock_t start = clock();
  for(int i=0; i<N; i++){
    D = i;
  }
  clock_t end = clock();
  cout << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";

  printf("インライン展開を利用したループ ");
  start = clock();
  REP(i,N)D=i;
  end = clock();

  cout << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";
  return 0;
}
