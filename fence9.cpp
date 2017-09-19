/*
ID: aman.ka1
PROG: fence9
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
bool EQ(double a, double b) { return abs(a-b) < 1e-6; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

struct Point {
	double x;
	double y;
	Point operator+(const Point& other) {return {x+other.x, y+other.y};}
	Point operator-(const Point& other) {return {x-other.x, y-other.y};}
	Point operator/(const double s) {return {x/s, y/s};}
};

void print(const Point& p) {
	cout << "{" << p.x << ", " << p.y << "}";
}

double cross(Point& p1, Point& p2) {
	return p1.x*p2.y - p1.y*p2.x;
}

bool onLine(Point p, Point l1, Point e) {
	Point l2 = e-l1, p2 = p-l1;
	return (fabs(cross(p, l1)) < .00000001 || fabs(cross(p2, l2)) < .00000001);
}

int main() {
    ifstream fin("fence9.in");
    ofstream fout("fence9.out");
    double n, m, p;
    fin >> n >> m >> p;
    bool obtuse = (p < m);
    Point t1 = {0, 0}, t2 = {n, m}, t3 = {p, 0};
    Point l1 = t2-t1, l2 = t3-t2, l3 = t1-t3;
    Point av = (t1+t2+t3)/3;
    
    /*print(t1);
    cout << " ";
    print(t2);
    cout << " ";
    print(t3);
    cout << endl;
    print(av);
    cout << endl;*/
    double c1, c2, c3;
    Point ptemp = av-t1;
    c1 = cross(l1, ptemp);
    ptemp = av-t2;
    c2 = cross(l2, ptemp);
    ptemp = av-t3;
    c3 = cross(l3, ptemp);
    //cout << c1 << " " << c2 << " " << c3 << endl;

    int ans = 0;
    double left = 0, right = p;
    
    for(double y = 1; y <= m-1; ++y) {
    	Point cur = {left, y};
    	Point ptemp2 = cur-t2, ptemp3 = cur-t3;
    	bool bad = false;
    	while(!(c1*cross(l1, cur) > 0 && c2*cross(l2, ptemp2) > 0 && c3*cross(l3, ptemp3) > 0) && cur.x <= max(n, p)) {
    		if(onLine(cur, t2, t3) && onLine({cur.x+1, cur.y}, t2, t3)) {
	    		bad = true;
	    		break;
	    	}
    		++cur.x;
    		++ptemp2.x;
    		++ptemp3.x;
    	}
    	left = cur.x;
    	if(bad) continue;
    	//cout << left << endl;
    	if(left > right) right = left;
    	cur.x = right;
    	ptemp2 = cur-t2;
    	ptemp3 = cur-t3;
    	if(obtuse) {
    		while(c1*cross(l1, cur) > 0 && c2*cross(l2, ptemp2) > 0 && c3*cross(l3, ptemp3) > 0 && cur.x-1 <= max(n, p)) {
    			//cout << cur.x << "  " << cross(l1, cur) << " " << cross(l2, cur) << " " << cross(l3, cur) << endl;
    			++cur.x;
    			++ptemp2.x;
    			++ptemp3.x;
    		}
    		right = cur.x-1;
    	} else {
    		while(!(c1*cross(l1, cur) > 0 && c2*cross(l2, ptemp2) > 0 && c3*cross(l3, ptemp3) > 0) && cur.x >= 0) {
    			--cur.x;
    			--ptemp2.x;
    			--ptemp3.x;
    		}
    		right = cur.x;
    	}
    	//cout << y << "  " << left << " " << right << endl;
    	if(left <= right) ans += (right-left+1);
    }
    fout << ans << endl;

    return 0;
}
