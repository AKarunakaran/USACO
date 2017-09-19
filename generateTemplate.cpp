#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	if(argc == 2) {
		ofstream fout(argv[1]);
		ifstream fin("template.cpp");
		string s;
		while(fin.good()) {
			getline(fin, s);
			if(s.substr(0, 5) == "PROG:") {
				int i = 0;
				while(argv[1][i] != '.') {
					s.push_back(argv[1][i]);
					++i;
				}
			}
			if(s.substr(0, 18) == "    ifstream fin(\"") {
				for(int i = 0; i < 6; ++i) s.pop_back();
				int i = 0;
				while(argv[1][i] != '.') {
					s.push_back(argv[1][i]);
					++i;
				}
				s = s + ".in\");";
			}
			if(s.substr(0, 19) == "    ofstream fout(\"") {
				for(int i = 0; i < 7; ++i) s.pop_back();
				int i = 0;
				while(argv[1][i] != '.') {
					s.push_back(argv[1][i]);
					++i;
				}
				s = s + ".out\");";
			}
			fout << s << endl;
		}
		string fileName;
		int i = 0;
		while(argv[1][i] != '.') {
			fileName.push_back(argv[1][i]);
			++i;
		}
		string inName = fileName + ".in";
		string outName = fileName + ".out";
		ofstream dotIn(inName.c_str());
		ofstream dotOut(outName.c_str());
	}
	
	return 0;
}