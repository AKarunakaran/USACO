/*
ID: aman.ka1
PROG: fracdec
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

int numDigits(int n) {
	if(n == 0) return 1;
	int d = 0;
	while(n) {
		n /= 10;
		++d;
	}
	return d;
}

int main() {
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");
    int n, d;
    fin >> n >> d;
    vector<int> num(100001, -1);
    int buff = numDigits(n/d);
    fout << n/d << ".";
    num[n%d] = 0;
    n = (n % d)*10;
    if(n == 0) {
    	fout << 0 << endl;
    	return 0;
    }
    string s;
    int i = 1;
    while(n && num[n%d] == -1) {
    	//cout << i << " " << n << " " << n%d << " " << n/d << endl;
    	s.push_back((n/d)+'0');
    	n %= d;
    	num[n] = i;
    	++i;
    	n *= 10;
    }

    if(n) {
    	s.push_back((n/d)+'0');
    	s.insert(num[n%d], "(");
    	s.push_back(')');
    }

    for(int j = buff+2; j < buff+2+s.size(); ++j) {
    	if(j % 76 == 1) fout << endl;
    	fout << s[j-(buff+2)];
    }
    fout << endl;

    return 0;
}
