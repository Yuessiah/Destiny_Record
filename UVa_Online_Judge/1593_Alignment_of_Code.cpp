#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<sstream>
const int maxline = 1000 + 10;

using namespace std;

vector<string> context[maxline];
vector<int> maxLength;
int line;

void printResult()
{
	for(int i = 0; i < line; i++) {
		int sz = context[i].size();
		for(int j = 0; j < sz; j++) {
			int len = (j<sz-1)? maxLength[j]+1 : 0;
			printf("%-*s", len, context[i][j].c_str());
		}
		cout << endl;
	}
}

int main()
{
	line = 0;
	string s;
	while(getline(cin, s)) {
		stringstream ss(s);
		string sec;
		while(ss >> sec) {
			context[line].push_back(sec);
			int col = context[line].size() - 1;
			if(maxLength.size() < context[line].size()) maxLength.push_back(sec.size());
			if(sec.size() > maxLength[col]) maxLength[col] = sec.size();
		}
		line++;
	}

	printResult();

	return 0;
}
