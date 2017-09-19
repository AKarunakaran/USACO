/*
ID: aman.ka1
PROG: preface
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
    ifstream fin("preface.in");
    ofstream fout("preface.out");
    int n;
    fin >> n;
    vector<char> lets = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<vector<int>> freqs(n+1, vector<int>(7, 0));
    FOR(i, 1, n) {
    	if(i >= 1000) {
    		freqs[i][6] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-1000][j];
    	} else if(i >= 900) {
    		freqs[i][4] = 1;
    		freqs[i][6] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-900][j];
    	} else if(i >= 500) {
    		freqs[i][5] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-500][j];
    	} else if(i >= 400) {
    		freqs[i][4] = 1;
    		freqs[i][5] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-400][j];
    	} else if(i >= 100) {
    		freqs[i][4] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-100][j];
    	} else if(i >= 90) {
    		freqs[i][2] = 1;
    		freqs[i][4] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-90][j];
    	} else if(i >= 50) {
    		freqs[i][3] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-50][j];
    	} else if(i >= 40) {
    		freqs[i][2] = 1;
    		freqs[i][3] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-40][j];
    	} else if(i >= 10) {
    		freqs[i][2] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-10][j];
    	} else if(i >= 9) {
    		freqs[i][0] = 1;
    		freqs[i][2] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-9][j];
    	} else if(i >= 5) {
    		freqs[i][1] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-5][j];
    	} else if(i >= 4) {
    		freqs[i][0] = 1;
    		freqs[i][1] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-4][j];
    	} else if(i >= 1) {
    		freqs[i][0] = 1;
    		REP(j, 7) freqs[i][j] += freqs[i-1][j];
    	}
    	//cout << i << " ";
    	//REP(j, 7) cout << freqs[i][j] << " ";
    	//cout << endl;
    }
    vector<int> sol(7, 0);
    REP(i, n+1) {
    	REP(j, 7) {
    		sol[j] += freqs[i][j];
    	}
    }
    int end = 6;
    while(!sol[end]) --end;
    int i = 0;
    while(i <= end) {
    	fout << lets[i] << " " << sol[i] << endl;
    	++i;
    }

    return 0;
}
