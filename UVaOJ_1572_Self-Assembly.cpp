#include<stdio.h>
#include<string.h>
const int maxa = 52;

int N;
bool G[maxa][maxa];
int C[maxa];

int normal(char c, char s) {
	return 2*(c-'A') + (s=='+'? 1 : 0);
}

void connect(char a, char b, char c, char d)
{
	if(a == '0' || c == '0') return;
	int u = normal(a, b)^1, v = normal(c, d);
	G[u][v] = 1;
}

bool topo(int u)
{
	C[u] = -1;
	for(int v = 0; v < maxa; v++) if(G[u][v]) {
		if(C[v] < 0) return true;
		if(!C[v] && topo(v)) return true;
	}
	C[u] = 1;
	return false;
}

bool circle()
{
	memset(C, 0, sizeof(C));

	for(int u = 0; u < maxa; u++) {
		if(!C[u] && topo(u)) return true;
	}
	return false;
}

int main()
{
	while(~scanf("%d", &N)) {
		memset(G, 0, sizeof(G));

		char m[10];
		while(N--) {
			scanf("%s", m);
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++) {
					if(i == j) continue;
					connect(m[2*i], m[2*i+1], m[2*j], m[2*j+1]);
				}
		}

		if(circle()) printf("un");
		printf("bounded\n");
	}

	return 0;
}
