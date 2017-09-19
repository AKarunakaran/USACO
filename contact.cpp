/*
ID: aman.ka1
PROG: contact
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
#include <unordered_map>
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
    ifstream fin("contact.in");
    ofstream fout("contact.out");
    int a, b, n;
    fin >> a >> b >> n;
    string s = "", in;
    s.reserve(200000);
    getline(fin, in);
    while(fin.good()) {
    	getline(fin, in);
    	s += in;
    }
    unordered_map<string, int> freqs;
    vector<pair<string, int>> pats;
    string seq;
    int sz = s.size();
    FOR(l, a, b) {
    	FOR(i, 0, sz-l) {
    		seq = s.substr(i, l);
    		if(freqs.find(seq) == freqs.end()) {
    			pats.push_back({seq, 0});
    			freqs[seq] = 0;
    		}
    		++freqs[seq];
    	}
    }
    REP(i, pats.size()) {
    	pats[i].second = freqs[pats[i].first];
    }
    sort(pats.begin(), pats.end(), [](pair<string, int>& left, pair<string, int>& right){return ((left.second == right.second) ? ((left.first.size() == right.first.size()) ? left.first < right.first : left.first.size() < right.first.size()) : left.second > right.second);});
    int idx = 0;
    REP(i, n) {
    	fout << pats[idx].second;
    	int j = idx;
    	while(pats[j].second == pats[idx].second) {
    		if((j-idx) % 6 == 0) fout << endl;
    		else fout << " ";
    		fout << pats[j].first;
    		++j;
    		if(j >= pats.size()) {
    			fout << endl;
    			return 0;
    		}
    	}
    	fout << endl;
    	idx = j;
    }

    return 0;
}
