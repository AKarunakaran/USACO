/*
ID: aman.ka1
PROG: combo
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

int n;

bool close(int a, int b) {
	int d = (a-b+n)%n;
	//cout << a << " " << b << " " << d << endl;
	return d >= n-2 || d <= 2;
}

int main() {
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    int f[3], m[3], ans = 0;
    fin >> n;
    REP(i, 3) fin >> f[i];
    REP(i, 3) fin >> m[i];
    FOR(i, 1, n) {
    	FOR(j, 1, n) {
    		FOR(k, 1, n) {
    			if(!((close(i, f[0]) && close(j, f[1]) && close(k, f[2])) || (close(i, m[0]) && close(j, m[1]) && close(k, m[2])))) continue;
    			++ans;
    			//cout << i << ',' << j << ',' << k << endl;
    		}
    	}
    }
    fout << ans << endl;

    return 0;
}