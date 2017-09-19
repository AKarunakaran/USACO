/*
ID: aman.ka1
PROG: sort3
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
////#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    int n;
    fin >> n;
    vector<int> list(n);
    vector<int> freq(4, 0);
    REP(i, n) {
    	fin >> list[i];
    	++freq[list[i]];
    }
    //REP(i, n) cout << list[i] << " ";
    //cout << endl;
    //cout << freq[1] << " " << freq[2] << " " << freq[3] << endl;
    int oneEnd = freq[1]-1;
    int twoEnd = oneEnd + freq[2];
    int threeEnd = twoEnd + freq[3];
    int oneIdx = 0, twoIdx = oneEnd+1, threeIdx = twoEnd+1;
    int swaps = 0;
    while(oneIdx <= oneEnd) {
    	if(list[oneIdx] == 2) {
    		while(twoIdx <= twoEnd) {
    			if(list[twoIdx] == 1) {
    				//DEBUG(oneIdx);
    				//DEBUG(twoIdx);
    				swap(list[oneIdx], list[twoIdx]);
    				++swaps;
    				++twoIdx;
    				break;
    			}
    			++twoIdx;
    		}
    	} else if(list[oneIdx] == 3) {
    		while(threeIdx <= threeEnd) {
    			if(list[threeIdx] == 1) {
    				//DEBUG(oneIdx);
    				//DEBUG(threeIdx);
    				swap(list[oneIdx], list[threeIdx]);
    				++swaps;
    				++threeIdx;
    				break;
    			}
    			++threeIdx;
    		}
    	}
    	++oneIdx;
    }
    twoIdx = oneEnd+1;
    threeIdx = twoEnd+1;
    while(twoIdx <= twoEnd) {
    	if(list[twoIdx] == 3) {
    		while(threeIdx <= threeEnd) {
    			if(list[threeIdx] == 2) {
    				swap(list[twoIdx], list[threeIdx]);
    				++swaps;
    				++threeIdx;
    				break;
    			}
    			++threeIdx;
    		}
    	}
    	++twoIdx;
    }
    //DEBUG(swaps);
    //REP(i, n) cout << list[i] << " ";
    //cout << endl;
    int wrong = 0;
    REP(i, n) {
    	if(i <= oneEnd) {
    		if(list[i] != 1) ++wrong;
    	} else if(i <= twoEnd) {
    		if(list[i] != 2) ++wrong;
    	} else if(i <= threeEnd) {
    		if(list[i] != 3) ++wrong;
    	}
    }
    swaps += ((wrong*2)/3);
    fout << swaps << endl;

    return 0;
}
