#include<string.h>

const int MAX = 1000;
int A, B, C, vis[MAX+1][MAX+1], path[MAX*MAX+1], p, DEST, SOURCE;

bool dfs(int a, int b)
{
	vis[a][b] = 1;
	if(a == C || b == C) return 1;

	if(!vis[A][b]) { path[p++] = 1; if(dfs(A, b)) return 1; p--; }
	if(!vis[a][B]) { path[p++] = 2; if(dfs(a, B)) return 1; p--; }

	if(!vis[0][b]) { path[p++] = 3; if(dfs(0, b)) return 1; p--; }
	if(!vis[a][0]) { path[p++] = 4; if(dfs(a, 0)) return 1; p--; }

	DEST = b+a > B ? B : b+a; SOURCE = a > (B-b) ? a - (B-b) : 0;
	if(!vis[SOURCE][DEST]) { path[p++] = 5; if(dfs(SOURCE, DEST)) return 1; p--; }
	DEST = a+b > A ? A : a+b; SOURCE = b > (A-a) ? b - (A-a) : 0;
	if(!vis[DEST][SOURCE]) { path[p++] = 6; if(dfs(DEST, SOURCE)) return 1; p--; }

	return 0;
}

void solve(int a, int b, int c)
{
	A = a; B = b; C = c;
	p = 0;
	dfs(0, 0);
	if(p) {
		for(int i = 0; i < p; i++) switch(path[i]) {
			case 1 : fill_1(); break;
			case 2 : fill_2(); break;
			case 3 : empty_1(); break;
			case 4 : empty_2(); break;
			case 5 : pour_1_to_2(); break;
			case 6 : pour_2_to_1(); break;
		} verify();
	} else no_solution();
	memset(vis, 0, sizeof(vis));
}
