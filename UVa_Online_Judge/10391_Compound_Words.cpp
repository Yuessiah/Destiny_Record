#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

set<string> dict;
vector<string> list;

int main()
{
	string word;
	while(cin >> word) {
		dict.insert(word);
		list.push_back(word);
	}

	int sz = list.size();
	for(int i = 0; i < sz; i++) {
		word = list[i];
		if(word.length() > 1) {
			int len = word.length();
			for(int j = 1; j < len; j++) if(\
					dict.count(word.substr(0, j)) && dict.count(word.substr(j))\
					) {
				cout << word << endl;
				break;
			}
		}
	}

	return 0;
}
