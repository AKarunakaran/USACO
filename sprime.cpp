/*
ID: aman.ka1
PROG: sprime
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

int d, b;

void genPrime(vector<int>& primes) {
	vector<bool> p(10001, 1);
	p[0] = p[1] = 0;
	for(int i = 2; i*i <= b; ++i) {
		if(p[i]) {
			for(int j = 2*i; j*j <= b; j += i) {
				p[j] = 0;
			}
		}
	}
	for(int i = 2; i*i <= b; ++i) {
		if(p[i]) primes.push_back(i);
	}
}

bool isPrime(int n, const vector<int>& primes) {
	if(n == 0 || n == 1) return false;
	REP(i, primes.size()) {
		if(primes[i]*primes[i] > n) break;
		if(n % primes[i] == 0) return false;
	}
	return true;
}

void perm(int n, int k, const vector<int>& primes, vector<int>& sol) {
	REP(i, 10) {
		if(isPrime(n, primes)) {
			if(k == d) sol.push_back(n);
			else perm(n*10, k+1, primes, sol);
		}
		++n;
	}
}

int main() {
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    fin >> d;
    b = pow(10, d);
    vector<int> primes;
    genPrime(primes);
    vector<int> sol;
    perm(0, 1, primes, sol);
    REP(i, sol.size()) fout << sol[i] << endl;

    return 0;
}
