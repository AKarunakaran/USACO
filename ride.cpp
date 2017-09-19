/*
ID: aman.ka1
PROG: ride
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
	ifstream fin("ride.in");
	ofstream fout("ride.out");
    string a, b;
    fin >> a >> b;
    int p1 = 1, p2 = 1;
    REP(i, a.size()) p1 = (p1 * (a[i] - 'A' + 1)) % 47;
    REP(i, b.size()) p2 = (p2 * (b[i] - 'A' + 1)) % 47;
    fout << ((p1 == p2) ? "GO" : "STAY") << endl;

    return 0;
}