/*
ID: aman.ka1
PROG: palsquare
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

bool isPal(const string& s) {
	REP(i, s.size()/2) if(s[i] != s[s.size()-1-i]) return false;
	return true;
}

string base(int n, int b) {
	string num;
	while(n) {
		if(n%b < 10) num.push_back(n%b + '0');
		else num.push_back(n%b - 10 + 'A');
		n /= b;
	}
	REP(i, num.size()/2) {
		char c = num[i];
		num[i] = num[num.size()-1-i];
		num[num.size()-1-i] = c;
	}
	return num;
}

int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int b;
    fin >> b;
    FOR(i, 1, 300) if(isPal(base(i*i, b))) fout << base(i, b) << " " << base(i*i, b) << endl;

    return 0;
}