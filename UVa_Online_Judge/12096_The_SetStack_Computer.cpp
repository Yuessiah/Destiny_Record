#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<map>
using namespace std;

map<set<int>, int> set_id;
vector<set<int> > set_pool;

int id(set<int> s)
{
	if(set_id.count(s)) return set_id[s];
	set_pool.push_back(s);
	return set_id[s] = set_pool.size() - 1;
}

int main()
{
	int T, N;
	cin >> T;

	while(T--) {
		stack<int> S;
		cin >> N;

		while(N--) {
			string cmd;
			cin >> cmd;

			if(cmd == "PUSH") S.push(id(set<int>()));
			else if(cmd == "DUP") S.push(S.top());
			else {
				set<int> s0;
				set<int> s1 = set_pool[S.top()]; S.pop();
				set<int> s2 = set_pool[S.top()]; S.pop();

				if(cmd == "UNION")
					set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s0, s0.begin()));
				if(cmd == "INTERSECT")
					set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s0, s0.begin()));
				if(cmd == "ADD") {
					s0 = s2;
					s0.insert(id(s1));
				}

				S.push(id(s0));
			}

			cout << set_pool[S.top()].size() << endl;
		}

		cout << "***" << endl;
	}

	return 0;
}
