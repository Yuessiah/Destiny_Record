#include<cstdio>
#include<cctype>
#include<queue>
#include<stack>
const int maxc = 10000 + 10;
using namespace std;

struct btree {
	int l, r;
} bt[maxc];

int resc;
char input[maxc], result[maxc];
stack<int> stk;

void btree_build()
{
	int i = 1;
	do {
		if(islower(input[i])) {
			bt[i].l = bt[i].r = 0;
		} else {
			bt[i].l = stk.top(); stk.pop();
			bt[i].r = stk.top(); stk.pop();
		}
		stk.push(i);
	}while(input[++i]);
}

void bfs()
{
	queue<int> q;
	q.push(stk.top()); stk.pop();
	while(!q.empty()) {
		int i = q.front(); q.pop();
		result[resc++] = input[i];
		if(bt[i].r) q.push(bt[i].r);
		if(bt[i].l) q.push(bt[i].l);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		resc = 0;
		scanf("%s", input+1);
		btree_build();
		bfs();
		for(int i = resc-1; i >= 0; i--) printf("%c", result[i]);
		putchar('\n');
	}
}
