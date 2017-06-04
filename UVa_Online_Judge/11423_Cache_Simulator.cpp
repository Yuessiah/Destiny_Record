#include<cstdio>
#include<cstring>
#define lowbit(x) x&-x
const int maxn = 30 + 5, maxd = (1<<24) + 10, maxr = 1e7 + 10;

int N, now, last[maxd], cache[maxn], miss[maxn], bit[maxr];

int sum(int x) {
	int s = 0;
	for(int i = x; i > 0; i-=lowbit(i)) s += bit[i];
	return s;
}

void update(int x, int val) {
	for(int i = x; i < maxr; i+=lowbit(i)) bit[i] += val;
}

void trace(int x) {
	if(last[x]) {
		int jetlag = sum(now) - sum(last[x]-1);
		for(int i = 0; i < N; i++) {
			if(jetlag <= cache[i]) break;
			miss[i]++;
		}

		update(last[x], -1);
	} else for(int i = 0; i < N; i++) miss[i]++;

	update(last[x] = ++now, 1);
}

void start() {
	char cmd[100];
	while(scanf("%s", cmd) && cmd[0] != 'E') {
		if(cmd[0] == 'A') {
			int x;
			scanf("%d", &x);
			trace(x);
		}
		if(cmd[0] == 'R') {
			int b, y, n;
			scanf("%d%d%d", &b, &y, &n);
			for(int k = 0; k < n; k++) trace(b+y*k);
		}
		if(cmd[0] == 'S') {
			for(int i = 0; i < N; i++) printf("%d%c", miss[i], i<N-1? ' ' : '\n');
			memset(miss, 0, sizeof(miss));
		}
	}
}

int main()
{
	memset(miss, 0, sizeof(miss));
	memset(last, 0, sizeof(last));
	now = 0;

	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &cache[i]);
	start();

	return 0;
}
