/*
ID: aman.ka1
PROG: pprime
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

int a, b;

int numDigits(int n) {
	int d = 0;
	while(n) {
		n /= 10;
		++d;
	}
	return d;
}

void genPrimes(vector<bool>& p, vector<int>& primes) {
	p[0] = p[1] = 0;
	for(int i = 2; i*i <= b; ++i) {
		if(p[i]) {
			for(int j = 2*i; j*j <= b; j += i) {
				p[j] = 0;
			}
		}
	}
	REP(i, 10001) {
		if(p[i]) primes.push_back(i);
	}
}

bool isPrime(int n, const vector<int>& primes) {
	REP(i, primes.size()) {
		if(primes[i]*primes[i] > n) break;
		if(n % primes[i] == 0) return false;
	}
	return true;
}

void genPerm(int d, int n, const vector<int>& primes, vector<int>& sol, int k) {
	int add;
	if(k == (d-1)/2 && d%2 == 1) {
		add = pow(10, k);
	} else {
		add = pow(10, k) + pow(10, d-1-k);
	}
	int r = 10 - (k == 0);
	REP(i, r) {
		if(n > b) break;
		if(k != (d-1)/2) {
			genPerm(d, n, primes, sol, k+1);
		} else {
			if(isPrime(n, primes)) sol.push_back(n);
		}
		n += add;
	}
}

int main() {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    fin >> a >> b;
    vector<bool> prime(10001, 1);
    vector<int> primes;
    vector<int> sol;
    genPrimes(prime, primes);
    int d1 = numDigits(a), d2 = numDigits(b);
    FOR(i, d1, d2) {
    	int n = (i == 1) ? 1 : (pow(10, i-1) + 1);
    	genPerm(i, n, primes, sol, 0);
    }
    REP(i, sol.size()) {
    	if(sol[i] < a || sol[i] > b) continue;
    	fout << sol[i] << endl;
    }

    return 0;
}
