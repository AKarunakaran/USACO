/*
ID: aman.ka1
PROG: frac1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

struct frac {
	int num;
	int den;
};

int gcd(int a, int b) {
	int c;
	while(b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    int n;
    fin >> n;
    vector<frac> sol;
    sol.push_back({0, 1});
    sol.push_back({1, 1});
    FOR(i, 2, n) {
    	FOR(j, 1, i-1) {
    		if(gcd(i, j) == 1) sol.push_back({j, i});
    	}
    }
    sort(sol.begin(), sol.end(), [](frac& left, frac& right){return (double) left.num/left.den < (double) right.num/right.den;});
    REP(i, sol.size()) fout << sol[i].num << '/' << sol[i].den << endl;

    return 0;
}
