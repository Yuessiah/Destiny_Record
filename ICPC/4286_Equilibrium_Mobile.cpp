#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int total;
string expr;
map<long long, int> base;

void dfs(int l, int r, int d)
{
	if(expr[l] == '[') {
		int pair = 0;
		for(int i = l+1; i < r; i++) {
			if(expr[i] == '[') pair++;
			if(expr[i] == ']') pair--;
			if(pair == 0 && expr[i] == ',') {
				dfs(l+1, i-1, d+1);
				dfs(i+1, r-1, d+1);
			}
		}
	} else {
		int c = 0;
		for(int i = l; isdigit(expr[i]); i++, c++);
		long long w = atoi(expr.substr(l, l+c+1).c_str());
		total++;
		base[w<<d]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while(T--) {
		total = 0;
		base.clear();

		cin >> expr;

		dfs(0, expr.length()-1, 0);
		int maxi = 0;
		for(auto i: base) maxi = max(maxi, i.second);

		cout << total-maxi << endl;
	}

	return 0;
}
