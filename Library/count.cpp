#include <bits/stdc++.h>
// x以上の要素の数を数える
template<typename T>
long long o_count(T x, vector<T> v) {
  long long cnt = 0;
  for (auto itr : v) {
    if (itr >= x){
      cnt++;
    }
  }
  return cnt;
}
