/*
ID: aman.ka1
PROG: subset
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
#define FOR(i,a,b) for(ull i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int n;

int main() {
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    fin >> n;
    if(n % 4 == 1 || n % 4 == 2) {
    	fout << 0 << endl;
    	return 0;
    }
    //vector<int> nSet(n, 0);
    //REP(i, n) nSet[i] = i+1;
    ull sum = n*(n+1)/4;
    vector<vector<ull>> subSums(sum+1, vector<ull>(n+1, 0));
    /*FOR(i, 1, sum) {
    	subSums[i][0] = 0;
    }
    FOR(i, 0, n) {
    	subSums[0][i] = 1;
    }*/
    subSums[0][0] = 1;
    FOR(i, 0, sum) {
    	FOR(j, 1, n) {
    		subSums[i][j] = subSums[i][j-1];
            if(i >= j) subSums[i][j] += subSums[i-j][j-1];
    	}
    }
    /*FOR(i, 0, sum) {
    	FOR(j, 0, n) {
    		cout << subSums[i][j] << " ";
    	}
    	cout << endl;
    }*/
    fout << subSums[sum][n]/2 << endl;

    return 0;
}
