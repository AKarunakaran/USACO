/*
ID: aman.ka1
PROG: castle
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

#define WEST 1
#define NORTH 2
#define EAST 4
#define SOUTH 8

struct module {
	bool w;
	bool n;
	bool e;
	bool s;
};

int main() {
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    int n, m, in;
    fin >> n >> m;
    vector< vector<module> > grid(m, vector<module>(n));
    REP(i, m) {
    	REP(j, n) {
    		fin >> in;
    		grid[i][j].w = 1-(bool)(in & WEST);
    		grid[i][j].n = 1-(bool)(in & NORTH);
    		grid[i][j].e = 1-(bool)(in & EAST);
    		grid[i][j].s = 1-(bool)(in & SOUTH);
    	}
    }

	/*REP(i, m) {
    	REP(j, n) {
    		cout << grid[i][j].w << grid[i][j].n << grid[i][j].e << grid[i][j].s << " ";
    	}
    	cout << endl;
    }*/

    vector<int> roomSize;
    vector< vector<int> > rooms(m, vector<int>(n, -1));
    vector< vector<bool> > checked(m, vector<bool>(n, 0));
    int cur = 0, size, r, c;
    REP(i, m) {
    	REP(j, n) {
    		if(rooms[i][j] == -1) {
    			//DEBUG(i);
    			//DEBUG(j);
    			queue<pair<int, int>> next;
    			size = 0;
    			next.push({i, j});
    			while(!next.empty()) {
    				r = next.front().first;
    				c = next.front().second;
    				next.pop();
    				if(checked[r][c]) continue;
    				rooms[r][c] = cur;
    				checked[r][c] = 1;
    				if(grid[r][c].w && !checked[r][c-1]) next.push({r, c-1});
					if(grid[r][c].n && !checked[r-1][c]) next.push({r-1, c});
					if(grid[r][c].e && !checked[r][c+1]) next.push({r, c+1});
					if(grid[r][c].s && !checked[r+1][c]) next.push({r+1, c});
					++size;
    			}
    			//cout << endl;
    			roomSize.push_back(size);
    			++cur;
    		}
    	}
    }

    int maxNR = 0;
    pair<int, int> maxNRwall;
    int maxNRwallD = -1;
    REP(i, m) {
    	REP(j, n) {
    		if(i != 0) {
    			if(!grid[i][j].n && rooms[i][j] != rooms[i-1][j]) {
    				if(roomSize[rooms[i][j]]+roomSize[rooms[i-1][j]] > maxNR) {
    					maxNR = roomSize[rooms[i][j]]+roomSize[rooms[i-1][j]];
    					maxNRwall = {i, j};
    					maxNRwallD = 1;
    				} else if(roomSize[rooms[i][j]]+roomSize[rooms[i-1][j]] == maxNR) {
    					if(j < maxNRwall.second || (j == maxNRwall.second && i > maxNRwall.first)) {
    						maxNR = roomSize[rooms[i][j]]+roomSize[rooms[i-1][j]];
	    					maxNRwall = {i, j};
	    					maxNRwallD = 1;
    					}
    				}
    			}
    		}
    		if(i != m-1) {
    			if(!grid[i][j].s && rooms[i][j] != rooms[i+1][j]) {
    				if(roomSize[rooms[i][j]]+roomSize[rooms[i+1][j]] > maxNR) {
    					maxNR = roomSize[rooms[i][j]]+roomSize[rooms[i+1][j]];
    					maxNRwall = {i, j};
    					maxNRwallD = 3;
    				} else if(roomSize[rooms[i][j]]+roomSize[rooms[i+1][j]] == maxNR) {
    					if(j < maxNRwall.second || (j == maxNRwall.second && i > maxNRwall.first)) {
    						maxNR = roomSize[rooms[i][j]]+roomSize[rooms[i+1][j]];
	    					maxNRwall = {i, j};
	    					maxNRwallD = 3;
    					}
    				}
    			}
    		}
    		if(j != 0) {
    			if(!grid[i][j].w && rooms[i][j] != rooms[i][j-1]) {
    				if(roomSize[rooms[i][j]]+roomSize[rooms[i][j-1]] > maxNR) {
    					maxNR = roomSize[rooms[i][j]]+roomSize[rooms[i][j-1]];
    					maxNRwall = {i, j};
    					maxNRwallD = 0;
    				} else if(roomSize[rooms[i][j]]+roomSize[rooms[i][j-1]] == maxNR) {
    					if(j < maxNRwall.second || (j == maxNRwall.second && i > maxNRwall.first)) {
    						maxNR = roomSize[rooms[i][j]]+roomSize[rooms[i][j-1]];
	    					maxNRwall = {i, j};
	    					maxNRwallD = 0;
    					}
    				}
    			}
    		}
    		if(j != n-1) {
    			if(!grid[i][j].e && rooms[i][j] != rooms[i][j+1]) {
    				if(roomSize[rooms[i][j]]+roomSize[rooms[i][j+1]] > maxNR) {
    					maxNR = roomSize[rooms[i][j]]+roomSize[rooms[i][j+1]];
    					maxNRwall = {i, j};
    					maxNRwallD = 2;
    				} else if(roomSize[rooms[i][j]]+roomSize[rooms[i][j+1]] == maxNR) {
    					if(j < maxNRwall.second || (j == maxNRwall.second && i > maxNRwall.first)) {
    						maxNR = roomSize[rooms[i][j]]+roomSize[rooms[i][j+1]];
	    					maxNRwall = {i, j};
	    					maxNRwallD = 2;
    					}
    				}
    			}
    		}
    	}
    }

    /*REP(i, roomSize.size()) cout << roomSize[i] << " ";
    cout << endl << endl;
    REP(i, m) {
    	REP(j, n) {
    		cout << rooms[i][j] << " ";
    	}
    	cout << endl;
    }*/

    int maxR = 0;
    REP(i, roomSize.size()) maxR = max(maxR, roomSize[i]);
    fout << roomSize.size() << endl << maxR << endl << maxNR << endl << (maxNRwall.first+1) << " " << (maxNRwall.second+1) << " ";
    if(maxNRwallD == 0) {
    	fout << 'W' << endl;
    }
    if(maxNRwallD == 1) {
    	fout << 'N' << endl;
    }
    if(maxNRwallD == 2) {
    	fout << 'E' << endl;
    }
    if(maxNRwallD == 3) {
    	fout << 'S' << endl;
    }

    return 0;
}
