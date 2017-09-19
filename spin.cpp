/*
ID: aman.ka1
PROG: spin
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

ull gcd(ull a, ull b) {
	if(a < b) {
		ull c = a;
		a = b;
		b = c;
	}
	while(b) {
		ull c = a % b;
		a = b;
		b = c;
	}
	return a;
}

struct wedge {
	int start;
	int end;
};

int main() {
    ifstream fin("spin.in");
    ofstream fout("spin.out");
    int n = 5, w;
    vector<int> speeds(n, 0);
    vector<vector<wedge>> wedges(n);
    REP(i, n) {
    	fin >> speeds[i] >> w;
    	wedges[i].resize(w);
    	REP(j, w) {
    		fin >> wedges[i][j].start >> wedges[i][j].end;
    		wedges[i][j].end = (wedges[i][j].start+wedges[i][j].end)%360;
    	}
    }
    int maxT = 360;
    REP(i, n) {
    	maxT = gcd(maxT, speeds[i]);
    }
    maxT = 360/maxT;
    REP(t, maxT) {
    	/*cout << t << endl;
    	REP(i, n) {
    		cout << speeds[i] << " ";
    		REP(j, wedges[i].size()) {
    			cout << wedges[i][j].start << " " << wedges[i][j].end << " ";
    		}
    		cout << endl;
    	}
    	cout << endl;*/
    	REP(i, 360) {
    		bool solved = true;
    		REP(j, n) {
    			bool good = false;
    			REP(k, wedges[j].size()) {
    				if(wedges[j][k].start <= wedges[j][k].end) {
    					if(i >= wedges[j][k].start && i <= wedges[j][k].end) {
	    					good = true;
	    					break;
	    				}
    				} else {
    					if(i >= wedges[j][k].start || i <= wedges[j][k].end) {
	    					good = true;
	    					break;
	    				}
    				}
    			}
    			if(!good) {
    				solved = false;
    				break;
    			}
    		}
    		if(solved) {
    			fout << t << endl;
    			return 0;
    		}
    	}
    	REP(i, n) {
    		REP(j, wedges[i].size()) {
    			wedges[i][j].start = (wedges[i][j].start+speeds[i])%360;
    			wedges[i][j].end = (wedges[i][j].end+speeds[i])%360;
    		}
    	}
    }
    fout << "none" << endl;

    return 0;
}
