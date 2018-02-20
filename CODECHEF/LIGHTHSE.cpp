#include<cstdio>

const int INF = 1e9 + 10;
const int maxn = 1e5 + 100;

int T, N, x[maxn], y[maxn];

int main()
{
	scanf("%d", &T);

	while(T--) {
		int max_x = -INF, max_y = -INF, min_x = INF, min_y = INF;
		int max_i, min_i;
		scanf("%d", &N);

		for(int i = 1; i <= N; i++) {
			scanf("%d%d", &x[i], &y[i]);
			if(x[i] > max_x) max_x = x[i];
			if(y[i] > max_y) max_y = y[i], max_i = i;
			if(x[i] < min_x) min_x = x[i];
			if(y[i] < min_y) min_y = y[i], min_i = i;
		}

		int idx = 0;
		char res[2];
		for(int i = 1; i <= N && !idx; i++) {
			if(x[i] == max_x) {
				res[1] = 'W';
				if(y[i] == max_y) res[0] = 'S', idx = i;
				if(y[i] == min_y) res[0] = 'N', idx = i;
			}
			if(x[i] == min_x) {
				res[1] = 'E';
				if(y[i] == max_y) res[0] = 'S', idx = i;
				if(y[i] == min_y) res[0] = 'N', idx = i;
			}
		}

		if(idx) printf("1\n%d %c%c\n", idx, res[0], res[1]);
		else {
			if(x[max_i] > x[min_i]) printf("2\n%d SW\n%d NE\n", max_i, min_i);
			else printf("2\n%d SE\n%d NW\n", max_i, min_i);
		}
	}

	return 0;
}
