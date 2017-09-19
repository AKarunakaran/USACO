/*
ID: aman.ka1
PROG: ttwo
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

vector<vector<bool>> g(12, vector<bool>(12, 1));

int nextRow(int r, int d) {
	return r+1-abs(d-2);
}

int nextCol(int c, int d) {
	return c+1-abs(d-1);
}

void move(int& fr, int& fc, int& fd, int& cr, int& cc, int& cd) {
    int nextR, nextC;
    nextR = nextRow(fr, fd);
    nextC = nextCol(fc, fd);
    if(!g[nextR][nextC]) {
        fd = (fd+1)%4;
    } else {
        fr = nextR;
        fc = nextC;
    }
    nextR = nextRow(cr, cd);
    nextC = nextCol(cc, cd);
    if(!g[nextR][nextC]) {
        cd = (cd+1)%4;
    } else {
        cr = nextR;
        cc = nextC;
    }
}

int main() {
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");
    int fr, fc, cr, cc, fsr, fsc, csr, csc;
    char c;
    REP(i, 12) {
    	g[i][0] = 0;
    	g[0][i] = 0;
    	g[i][11] = 0;
    	g[11][i] = 0;
    }
    REP(i, 10) {
    	REP(j, 10) {
    		fin >> c;
    		if(c == '*') g[i+1][j+1] = 0;
    		if(c == 'F') {
    			fsr = i+1;
    			fsc = j+1;
    		}
    		if(c == 'C') {
    			csr = i+1;
    			csc = j+1;
    		}
    	}
    }
    fr = fsr;
    fc = fsc;
    cr = csr;
    cc = csc;
    int fd = 0, cd = 0;
    int cnt = 0;
    while(!((fr == cr) && (fc == cc))) {
        //cout << cnt << endl;
        //cout << fr << "," << fc << " " << fd << endl;
        //cout << cr << "," << cc << " " << cd << endl;
        //cout << endl;
        if(cnt > 160000) {
            fout << 0 << endl;
            return 0;
        }
        move(fr, fc, fd, cr, cc, cd);
        ++cnt;
    }
    fout << cnt << endl;

    return 0;
}
