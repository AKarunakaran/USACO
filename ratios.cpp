/*
ID: aman.ka1
PROG: ratios
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

int amt[3], mix[3][3], goal[3], cur[3], sol[3], n = 3, solR;
ifstream fin("ratios.in");
ofstream fout("ratios.out");

bool good(int& r) {
	REP(i, n) if(goal[i] && cur[i] % goal[i] != 0) return false;
	if(goal[0]) r = cur[0]/goal[0];
	else if(goal[1]) r = cur[1]/goal[1];
	else r = cur[2]/goal[2];
	//cout << r << endl;
	REP(i, n) if(goal[i]*r != cur[i]) return false;
	return true;
}

int main() {
    REP(i, n) amt[i] = 0;
    REP(i, n) fin >> goal[i];
    REP(i, n) REP(j, n) fin >> mix[i][j];
    int s = 300;
    REP(a, 100) {
    	REP(b, 100) {
    		REP(c, 100) {
    			if(a + b + c >= s || !(a || b || c)) continue;
    			//cout << a << " " << b << " " << c << endl;
    			REP(i, n) cur[i] = a*mix[0][i] + b*mix[1][i] + c*mix[2][i];
    			//cout << cur[0] << " " << cur[1] << " " << cur[2] << endl;
    			int r;
    			if(good(r)) {
    				sol[0] = a;
    				sol[1] = b;
    				sol[2] = c;
    				s = a + b + c;
    				solR = r;
    			}
    			//cout << endl;
    		}
    	}
    }
    if(s == 300) {
    	fout << "NONE" << endl;
    } else {
    	REP(i, n) fout << sol[i] << " ";
    	fout << solR << endl;
    }

    return 0;
}
