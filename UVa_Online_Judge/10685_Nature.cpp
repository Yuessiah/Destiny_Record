#include<bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 100;

int C, R;
int group[maxn], chain_cnt[maxn];
map<string, int> creature_no;

int find(int c)
{
	while(c != group[c]) c = group[c];
	return c;
}

int main()
{
	while(~scanf("%d%d", &C, &R) && (C || R)) {
		creature_no.clear();
		for(int i = 1; i <= C; i++) chain_cnt[i] = 0;

		for(int i = 1; i <= C; i++) {
			string creature;
			cin >> creature;
			creature_no[creature] = i;
			group[i] = i;
		}

		for(int l = 0; l < R; l++) {
			string prey, predator;
			cin >> prey >> predator;
			int a = find(creature_no[prey]), b = find(creature_no[predator]);
			group[a] = b;
		}

		int maxi = 0;
		for(int i = 1; i <= C; i++) {
			int& cnt = ++chain_cnt[find(i)];
			if(maxi < cnt) maxi = cnt;
		}

		cout << maxi << "\n";
	}

	return 0;
}
