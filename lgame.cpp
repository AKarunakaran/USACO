/*
ID: aman.ka1
PROG: lgame
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
#include <unordered_set>
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

string lets;

void choose(int k, int l, vector<string>& itrWords, string& cur) {
	if(l == 0) {
		itrWords.push_back(cur);
		return;
	}
	if(lets.size()-k < l) return;
	cur.push_back(lets[k]);
	choose(k+1, l-1, itrWords, cur);
	cur.pop_back();
	choose(k+1, l, itrWords, cur);
}

int main() {
    ifstream fin("lgame.in");
    ifstream dict("lgame.dict");
    ofstream fout("lgame.out");
    fin >> lets;
    vector<int> letScores = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
    vector<string> words;
    unordered_map<string, vector<int>> sortedWords;
    vector<pair<string, string>> ans;
    string inWord;
    int wordNum = 0;
    dict >> inWord;
    while(inWord[0] != '.') {
    	words.push_back(inWord);
    	sort(inWord.begin(), inWord.end());
    	sortedWords[inWord].push_back(wordNum);
    	++wordNum;
    	dict >> inWord;
    }
    int best = 0;
    FORD(l, lets.size(), 1) {
    	vector<string> itrWords;
    	string temp = "";
    	choose(0, l, itrWords, temp);
    	unordered_set<string> usedBases;
    	REP(w, itrWords.size()) {
    		temp = itrWords[w];
    		sort(temp.begin(), temp.end());
    		if(usedBases.find(temp) != usedBases.end()) continue;
    		else usedBases.insert(temp);

    		auto& base = itrWords[w];
    		//DEBUG(base);

    		int sum = 0;
    		REP(i, l) sum += letScores[base[i]-'a'];
    		if(sum < best) continue;
    		unordered_set<string> used;
    		REP(i, two(l)) {
    			int hamm = 0;
    			REP(j, l) if(i & two(j)) ++hamm;
    			if((l%2 == 0 && hamm < l/2) || (l%2 == 1 && hamm <= l/2)) continue;

    			string w1, w2;
    			REP(j, l) {
    				if(i & two(j)) w1.push_back(base[j]);
    				else w2.push_back(base[j]);
    			}
    			sort(w1.begin(), w1.end());
    			sort(w2.begin(), w2.end());
    			if(used.find(w1) != used.end()) continue;
    			else {
    				used.insert(w1);
    				used.insert(w2);
    			}
    			//DEBUG(w1);
    			//DEBUG(w2);
    			if(w2.size() == 0) {
    				if(sortedWords.find(w1) != sortedWords.end()) {
    					if(sum > best) {
    						best = sum;
    						ans.resize(0);
    					}
    					//cout << "Good " << i << endl;
    					auto& v = sortedWords[w1];
    					REP(j, v.size()) ans.push_back({words[v[j]], ""});
    				}
    			} else if(sortedWords.find(w1) != sortedWords.end() && sortedWords.find(w2) != sortedWords.end()) {
    				if(sum > best) {
						best = sum;
						ans.resize(0);
					}
					//cout << "Good " << i << endl;
					auto& v1 = sortedWords[w1];
					auto& v2 = sortedWords[w2];
					REP(j, v1.size()) REP(k, v2.size()) ans.push_back({words[v1[j]], words[v2[k]]});
    			}
    		}
    	}
    }
    REP(i, ans.size()) {
    	if(ans[i].second.size() != 0) {
    		string w1 = min(ans[i].first, ans[i].second);
    		string w2 = max(ans[i].first, ans[i].second);
    		ans[i].first = w1;
    		ans[i].second = w2;
    	}
    }
    sort(ans.begin(), ans.end());
    fout << best << endl;
    REP(i, ans.size()) {
    	if(ans[i].second.size() == 0) {
    		fout << ans[i].first << endl;
    	} else {
    		fout << ans[i].first << " " << ans[i].second << endl;
    	}
    }

    return 0;
}
