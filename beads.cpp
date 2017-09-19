/*
ID: aman.ka1
PROG: beads
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
int n, maxl = 0;
string s;

void updateMax(int start, int end) {
    int ridx = (start-1+n)%n;
    while(s[(ridx-1+n)%n] != 'b') ridx = (ridx-1+n)%n;
    maxl = max(maxl, ((ridx > end) ? n-(ridx-end-1) : end-ridx+1));
    ridx = (end+1)%n;
    while(s[(ridx+1)%n] != 'b') ridx = (ridx+1)%n;
    maxl = max(maxl, ((ridx > start) ? ridx-start+1 : n-(start-ridx-1)));
}

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int fs;
    fin >> n >> s;
    int start = 0, end, ridx;
    int i = 0;
    for(; i < n; ++i) if(s[i] == 'r') break;
    if(i == n) {
        fout << n << endl;
        return 0;
    }
    for(i = 0; i < n; ++i) if(s[i] == 'b') break;
    if(i == n) {
        fout << n << endl;
        return 0;
    }
    while(s[start] == 'r' && start < n) ++start;
    //cout << start << endl;
    while(s[(start-1+n)%n] != 'r' && (start-1+n)%n != 0) start = (start-1+n)%n;
    //cout << start << endl;
    end = start;
    while(s[(end+1)%n] != 'r' && (end+1)%n != start) end = (end+1)%n;
    //cout << end << endl;
    updateMax(start, end);
    //cout << start << " " << end << " " << maxl << endl;
    fs = start;
    start = (end+1)%n;
    while(s[start] == 'r') start = (start+1)%n;
    while(start != fs) {
        while(s[(start-1+n)%n] != 'r') start = (start-1+n)%n;
        end = start;
        while(s[(end+1)%n] != 'r' && (end+1)%n != start) end = (end+1)%n;
        updateMax(start, end);
        //cout << start << " " << end << " " << maxl << endl;
        start = (end+1)%n;
        while(s[start] == 'r') start = (start+1)%n;
    }
    fout << maxl << endl;

    return 0;
}