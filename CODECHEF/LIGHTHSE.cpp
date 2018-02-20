#include<cstdio>

const int INF = 1e9 + 10;
const int maxn = 1e5 + 100;

int T, N, x[maxn], y[maxn];

int main()
{
	scanf("%d", &T);

	while(T--) {
		int lo_y =  INF, r_lo_x = -INF, l_lo_x = INF, r_lo_i, l_lo_i;
		int hi_y = -INF, r_hi_x = -INF, l_hi_x = INF, r_hi_i, l_hi_i;
		scanf("%d", &N);

		for(int i = 1; i <= N; i++) {
			scanf("%d%d", &x[i], &y[i]);
			if(y[i] > hi_y) hi_y = y[i];
			if(y[i] < lo_y) lo_y = y[i];
		}

		for(int i = 1; i <= N; i++)  {
			if(y[i] == hi_y) {
				if(x[i] > r_hi_x) r_hi_x = x[i], r_hi_i = i;
				if(x[i] < l_hi_x) l_hi_x = x[i], l_hi_i = i;
			}
			if(y[i] == lo_y) {
				if(x[i] > r_lo_x) r_lo_x = x[i], r_lo_i = i;
				if(x[i] < l_lo_x) l_lo_x = x[i], l_lo_i = i;
			}
		}

		bool r_hi_cnt = false, l_hi_cnt = false;
		bool r_lo_cnt = false, l_lo_cnt = false;
		for(int i = 1; i <= N; i++) {
			if(x[i] > r_hi_x) r_hi_cnt = true;
			if(x[i] < l_hi_x) l_hi_cnt = true;
			if(x[i] > r_lo_x) r_lo_cnt = true;
			if(x[i] < l_lo_x) l_lo_cnt = true;
		}

		if     (!r_hi_cnt) printf("1\n%d SW\n", r_hi_i);
		else if(!l_hi_cnt) printf("1\n%d SE\n", l_hi_i);
		else if(!r_lo_cnt) printf("1\n%d NW\n", r_lo_i);
		else if(!l_lo_cnt) printf("1\n%d NE\n", l_lo_i);
		else if(r_hi_x > r_lo_x) printf("2\n%d SW\n%d NE\n", r_hi_i, r_lo_i);
		else printf("2\n%d SE\n%d NW\n", r_hi_i, r_lo_i);
	}

	return 0;
}
