#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int total, ec;
string expr;
map<long long, int> base;

void dfs(int d)
{
	if(expr[ec] == '[') {
		ec++;
		dfs(d+1); ec++;
		dfs(d+1); ec++;
	} else {
		int s = ec, c = 0;
		while(isdigit(expr[ec])) c++, ec++;
		long long w = atoi(expr.substr(s, s+c+1).c_str());
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
		total = ec = 0;
		base.clear();

		cin >> expr;

		dfs(0);
		int maxi = 0;
		for(auto i: base) maxi = max(maxi, i.second);

		cout << total-maxi << endl;
	}

	return 0;
}
