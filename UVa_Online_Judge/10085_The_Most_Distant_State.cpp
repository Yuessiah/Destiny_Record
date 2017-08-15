#include<cstdio>
#include<cstring>
#include<vector>
using std::vector;

const int hashsize = 1e6 + 3, maxs = 1e6;
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
const char dir[] = {'U', 'L', 'D', 'R'};

int head[hashsize], next[maxs];
int kase=0;

typedef int state[9];
state st[maxs], a;

struct path {
	int fa, dir;
}P[maxs];


int find_zero(state s) { for(int i = 0; i < 9; i++) if(s[i] == 0) return i; }

int hash(state& s) {
	int v = 0;
	for(int i = 0; i < 9; i++) v = v*10 + s[i];
	return v % hashsize;
}

bool try_to_insert(int s) {
	int h = hash(st[s]);
	int u = head[h];
	while(u) {
		if(!memcmp(st[u], st[s], sizeof(st[s]))) return false;
		u = next[u];
	}

	next[s] = head[h];
	head[h] = s;
	return true;
}

void bfs() {
	memcpy(st[0], a, sizeof(a));
	P[0].fa = -1;

	int rear = 1, front = 0;
	while(front != rear) {
		state& now = st[front];
		state nxt;
		int now_z = find_zero(now);
		int x = now_z%3, y = now_z/3;

		for(int d = 0; d < 4; d++) {
			int nx = x+dx[d], ny = y+dy[d];
			if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			memcpy(nxt, now, sizeof(now));
			int nxt_z = ny*3 + nx;
			nxt[nxt_z] = 0;
			nxt[now_z] = now[nxt_z];

			memcpy(st[rear], nxt, sizeof(nxt));
			P[rear].fa = front; P[rear].dir = d;
			if(try_to_insert(rear)) rear++;
		}

		front++;
	}

	printf("Puzzle #%d\n", ++kase);
	for(int i = 0; i < 9; i++) printf("%d%c", st[front-1][i], ((i+1)%3!=0)? ' ' : '\n');
	vector<char> tmp;
	for(int i = front-1; P[i].fa != -1; i=P[i].fa) tmp.push_back(dir[P[i].dir]);
	for(int i = tmp.size()-1; i >= 0; i--) putchar(tmp[i]);
	printf("\n\n");
}

void init() {
	memset(head, 0, sizeof(head));
	memset(next, 0, sizeof(next));
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		init();

		for(int i = 0; i < 9; i++) scanf("%d", &a[i]);
		bfs();
	}

	return 0;
}
