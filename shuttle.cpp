/*
ID: aman.ka1
PROG: shuttle
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

void print(vector<int>& board) {
	REP(i, board.size()) cout << ((board[i] == 1) ? 'W' : ((board[i] == 2) ? 'B' : ' '));
	cout << endl;
}

bool done(vector<int>& board) {
	REP(i, board.size()/2) if(board[i] != 2 || board[board.size()-1-i] != 1) return false;
	return true;
}

bool good(int p, int hole, vector<int> board) {
	board[hole] = board[p];
	board[p] = 0;
	hole = p;
	//print(board);
	int fb = 0, fw = 0;
	REP(i, board.size()/2) {
		if(board[i] == 2) ++fb;
		else break;
	}
	REP(i, board.size()/2) {
		if(board[board.size()-1-i] == 1) ++fw;
		else break;
	}
	FOR(i, 0, hole) {
		if(board[i] == 2 && board[i+1] == 2 && fb < i+1) return false;
	}
	FOR(i, hole, board.size()-2) {
		if(board[i] == 1 && board[i+1] == 1 && fw < (board.size()-1-i)+1) return false;
	}
	if(hole > 0 && hole < board.size()-1) {
		if(board[hole-1] == 2 && board[hole+1] == 1 && board.size()-1-hole != fw && hole != fb) return false;
	}
	return true;
}

int main() {
    ifstream fin("shuttle.in");
    ofstream fout("shuttle.out");
    int n;
    fin >> n;
    vector<int> board(2*n+1, 0);
    vector<int> ans;
    REP(i, n) board[i] = 1;
    REP(i, n) board[2*n-i] = 2;
    int hole = n;
    
    while(!done(board)) {
    	//print(board);
    	//DEBUG(hole);
    	FOR(i, -2, 2) {
    		if(hole+i < 0 || hole+i > 2*n) continue;
    		if(i == -2 && (board[hole-1] == 1 || board[hole-2] == 2)) continue;
    		if(i == -1 && board[hole-1] == 2) continue;
    		if(i == 0) continue;
    		if(i == 1 && board[hole+1] == 1) continue;
    		if(i == 2 && (board[hole+1] == 2 || board[hole+2] == 1)) continue;
    		//DEBUG(i);
    		if(good(hole+i, hole, board)) {
    			board[hole] = board[hole+i];
    			board[hole+i] = 0;
    			hole = hole+i;
    			ans.push_back(hole);
    			break;
    		}
    	}
    }

    REP(i, ans.size()-1) fout << ans[i]+1 << (((i+1) % 20 == 0) ? '\n' : ' ');
    fout << ans.back()+1 << endl;

    return 0;
}
