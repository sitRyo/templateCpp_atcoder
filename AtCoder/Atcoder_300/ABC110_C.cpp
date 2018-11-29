#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

typedef long long LL;

#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

std::string S, T;

int main()
{
	in >> S >> T;
	std::vector<char>cngS(30, '\0'), cngT(30, '\0');
	rep(i, S.length())
	{
		if (cngS[S[i] - 'a'] == '\0') cngS[S[i] - 'a'] = T[i];
		if (cngT[T[i] - 'a'] == '\0') cngT[T[i] - 'a'] = S[i];
		if (cngS[S[i] - 'a'] != T[i])
		{
			out << "No" << std::endl;
			return 0;
		}
		if (cngT[T[i] - 'a'] != S[i])
		{
			out << "No" << std::endl;
			return 0;
		}
	}
	out << "Yes" << std::endl;
	return 0;
}
