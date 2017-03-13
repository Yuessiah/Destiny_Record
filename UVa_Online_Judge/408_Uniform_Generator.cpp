#include<cstdio>
#include<cstring>
const int maxn = 100000 + 100;

bool map[maxn];

int main()
{
	int a, b, c = 0;
	while(~scanf("%d%d", &a, &b)) {
		memset(map, 0, sizeof(map));
		bool ok = true;

		while(1) {
			c = (c+a)%b;
			if(map[c]) {
				for(int i = 1; i < b; i++) if(!map[i]) { ok = false; break; }
				break;
			}
			map[c] = 1;
		}

		printf("%10d%10d    ", a, b);
		if(ok) printf("Good Choice");
		else printf("Bad Choice");
		printf("\n\n");
	}

	return 0;
}

