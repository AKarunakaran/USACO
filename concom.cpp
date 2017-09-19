/*
ID: aman.ka1
PROG: concom
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
    ifstream fin("concom.in");
    ofstream fout("concom.out");
    int n = 0;
    int l;
    fin >> l;
    int in1, in2, in3;
    vector<vector<int>> g(100, vector<int>(100, 0));
    REP(i, l) {
    	fin >> in1 >> in2 >> in3;
    	n = max(n, max(in1, in2));
    	g[in1-1][in2-1] = in3;
    }
    int cur;
    REP(i, n) {
    	vector<bool> checked(n, 0);
    	vector<int> own(n, 0);
    	queue<int> next;
    	checked[i] = 1;
    	next.push(i);
    	while(!next.empty()) {
    		cur = next.front();
    		next.pop();
    		REP(j, n) {
    			own[j] += g[cur][j];
    			if(own[j] > 50 && !checked[j]) {
    				checked[j] = 1;
    				next.push(j);
    			}
    		}
    	}
    	REP(j, n) {
    		if(own[j] > 50 && i != j) {
    			fout << i+1 << " " << j+1 << endl;
    		}
    	}
    }

    return 0;
}
