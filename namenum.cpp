/*
ID: aman.ka1
PROG: namenum
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
#include <deque>
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

vector< vector<char> > numAssign = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}};

void genNames(const string& num, const vector<string>& dict, vector<string>& valid, string cur, int k) {
	if(cur.size() == num.size()) {
		//cout << cur << endl;
		bool found = false;
		REP(i, dict.size()) {
			if(dict[i] == cur) {
				found = true;
				break;
			}
		}
		if(found) {
			valid.push_back(cur);
		}
		return;
	}
	REP(i, 3) {
		cur.push_back(numAssign[num[k]-'0'-2][i]);
		genNames(num, dict, valid, cur, k+1);
		cur.pop_back();
	}
	return;
}

int main() {
	/*FOR(i, 2, 9) {
		REP(j, 3) {
			cout << numAssign[i-2][j] << " ";
		}
		cout << endl;
	}*/
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream fname("dict.txt");
    string num, in;
    vector<string> names;
    fin >> num;
    while(fname.good()) {
    	fname >> in;
    	if(in.size() == num.size()) names.push_back(in);
    }
    //REP(i, names.size()) cout << names[i] << endl;
    in = "";
    vector<string> valid;
    genNames(num, names, valid, in, 0);
    sort(valid.begin(), valid.end());
   	if(valid.size()) REP(i, valid.size()) fout << valid[i] << endl;
   	else fout << "NONE" << endl;

    return 0;
}