/*
ID: aman.ka1
PROG: maze1
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

struct module {
	bool w;
	bool n;
	bool e;
	bool s;
};

int main() {
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");
    int w, h, e1r = -1, e1c = -1, e2r = -1, e2c = -1;
    fin >> w >> h;
    vector<vector<module>> maze(h, vector<module>(w, {0, 0, 0, 0}));
    vector<vector<char>> input(2*h+1, vector<char>(2*w+1));
    string s;
    getline(fin, s);
    REP(i, 2*h+1) {
    	getline(fin, s);
    	REP(j, 2*w+1) {
    		input[i][j] = s[j];
    	}
    }

    REP(i, h) {
    	REP(j, w) {
    		maze[i][j].w = (input[2*i+1][2*j] == ' ');
    		maze[i][j].n = (input[2*i][2*j+1] == ' ');
    		maze[i][j].e = (input[2*i+1][2*j+2] == ' ');
    		maze[i][j].s = (input[2*i+2][2*j+1] == ' ');
    	}
    }

    REP(i, h) {
    	REP(j, w) {
    		if(i == 0 && maze[i][j].n) {
    			maze[i][j].n = 0;
    			if(e1r == -1) {
    				e1r = i;
    				e1c = j;
    			} else {
    				e2r = i;
    				e2c = j;
    				break;
    			}
    		}
    		if(i == h-1 && maze[i][j].s) {
    			maze[i][j].s = 0;
    			if(e1r == -1) {
    				e1r = i;
    				e1c = j;
    			} else {
    				e2r = i;
    				e2c = j;
    				break;
    			}
    		}
    		if(j == 0 && maze[i][j].w) {
    			maze[i][j].w = 0;
    			if(e1r == -1) {
    				e1r = i;
    				e1c = j;
    			} else {
    				e2r = i;
    				e2c = j;
    				break;
    			}
    		}
    		if(j == w-1 && maze[i][j].e) {
    			maze[i][j].e = 0;
    			if(e1r == -1) {
    				e1r = i;
    				e1c = j;
    			} else {
    				e2r = i;
    				e2c = j;
    				break;
    			}
    		}
    	}
    }

    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[e1r][e1c] = dist[e2r][e2c] = 1;
    queue<pair<int, int>> next;
    next.push({e1r, e1c});
    while(!next.empty()) {
    	int curX = next.front().first, curY = next.front().second;
    	next.pop();
    	if(maze[curX][curY].n && dist[curX-1][curY] > dist[curX][curY]+1) {
    		next.push({curX-1, curY});
    		dist[curX-1][curY] = dist[curX][curY]+1;
    	}
    	if(maze[curX][curY].s && dist[curX+1][curY] > dist[curX][curY]+1) {
    		next.push({curX+1, curY});
    		dist[curX+1][curY] = dist[curX][curY]+1;
    	}
    	if(maze[curX][curY].w && dist[curX][curY-1] > dist[curX][curY]+1) {
    		next.push({curX, curY-1});
    		dist[curX][curY-1] = dist[curX][curY]+1;
    	}
    	if(maze[curX][curY].e && dist[curX][curY+1] > dist[curX][curY]+1) {
    		next.push({curX, curY+1});
    		dist[curX][curY+1] = dist[curX][curY]+1;
    	}
    }
    next.push({e2r, e2c});
    while(!next.empty()) {
    	int curX = next.front().first, curY = next.front().second;
    	next.pop();
    	if(maze[curX][curY].n && dist[curX-1][curY] > dist[curX][curY]+1) {
    		next.push({curX-1, curY});
    		dist[curX-1][curY] = dist[curX][curY]+1;
    	}
    	if(maze[curX][curY].s && dist[curX+1][curY] > dist[curX][curY]+1) {
    		next.push({curX+1, curY});
    		dist[curX+1][curY] = dist[curX][curY]+1;
    	}
    	if(maze[curX][curY].w && dist[curX][curY-1] > dist[curX][curY]+1) {
    		next.push({curX, curY-1});
    		dist[curX][curY-1] = dist[curX][curY]+1;
    	}
    	if(maze[curX][curY].e && dist[curX][curY+1] > dist[curX][curY]+1) {
    		next.push({curX, curY+1});
    		dist[curX][curY+1] = dist[curX][curY]+1;
    	}
    }
    int ans = 0;
    REP(i, h) {
    	REP(j, w) {
    		//cout << dist[i][j] << " ";
    		ans = max(ans, dist[i][j]);
    	}
    	//cout << endl;
    }
    fout << ans << endl;

    return 0;
}
