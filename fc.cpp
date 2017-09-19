/*
ID: aman.ka1
PROG: fc
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

struct point {
	double x;
	double y;
	point operator+(const point& other) {return {x+other.x, y+other.y};}
	point operator-(const point& other) {return {x-other.x, y-other.y};}
};

double cross(point p1, point p2) {
	return p1.x*p2.y-p1.y*p2.x;
}

double dist(const point& p1, const point& p2) {
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int main() {
    ifstream fin("fc.in");
    ofstream fout("fc.out");
    fout << fixed << setprecision(2);
    int n;
    double midx = 0, midy = 0;
    fin >> n;
    vector<pair<point, double>> pts(n);
    REP(i, n) {
    	fin >> pts[i].first.x >> pts[i].first.y;
    	midx += pts[i].first.x;
    	midy += pts[i].first.y;
    }
    midx /= n;
    midy /= n;
    if(n == 3) {
    	double ans = 0;
    	FOR(i, 0, 2) ans += dist(pts[i%3].first, pts[(i+1)%3].first);
    	fout << ans << endl;
    	return 0;
    }
    if(n == 2) {
    	fout << dist(pts[0].first, pts[1].first) << endl;
        return 0;
    }
    if(n < 2) {
    	fout << 0 << endl;
    	return 0;
    }
    REP(i, n) {
        double ang = atan2(pts[i].first.y-midy, pts[i].first.x-midx);
        pts[i].second = (ang < 0) ? ang + 2*3.141592654 : ang;
    }
    sort(pts.begin(), pts.end(), [](pair<point, double>& left, pair<point, double>& right){return left.second < right.second;});

    vector<point> hull;
    hull.push_back(pts[0].first);
    hull.push_back(pts[1].first);
    int hsz = 2;
    FOR(i, 2, n-2) {
    	while(hsz > 1 && cross(hull[hsz-1]-hull[hsz-2], pts[i].first-hull[hsz-1]) < 0) {
    		hull.pop_back();
            --hsz;
    	}
        hull.push_back(pts[i].first);
        ++hsz;
    }
    point last = pts.back().first;
    while(hsz > 1 && cross(hull[hsz-1]-hull[hsz-2], last-hull[hsz-1]) < 0) {
        hull.pop_back();
        --hsz;
    }
    int hullstart = 0;
    bool flag = false;
    do {
        flag = false;
    	if(hsz-hullstart >= 2 && cross(last-hull[hsz-1], hull[hullstart]-last) < 0) {
    		last = hull.back();
            hull.pop_back();
            --hsz;
    		flag = true;
    	}
    	if(hsz-hullstart >= 2 && cross(hull[hullstart]-last, hull[hullstart+1]-hull[hullstart]) < 0) {
    		++hullstart;
    		flag = true;
    	}
    } while(flag);
    hull.push_back(last);
    ++hsz;
    double ans = 0;
    FOR(i, hullstart, hsz-2) ans += dist(hull[i], hull[i+1]);
    ans += dist(hull[hsz-1], hull[hullstart]);
    fout << ans << endl;

    return 0;
}
