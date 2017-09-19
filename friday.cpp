/*
ID: aman.ka1
PROG: friday
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

int main() {
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    vector<int> days = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> freq(7, 0);
    int n, d = 4;
    fin >> n;
    FOR(y, 1900, 1899+n) {
    	FOR(m, 1, 12) {
    		d = (d + days[m-1] + (((y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))) && m == 3)) % 7;
	    	++freq[d];
	    }
    }
    REP(i, 6) fout << freq[i] << " ";
    fout << freq.back() << endl;

    return 0;
}