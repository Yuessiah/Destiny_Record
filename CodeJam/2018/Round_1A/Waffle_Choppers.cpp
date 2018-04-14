#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;

int R, C, H, V, row[maxn], col[maxn], hor[maxn], ver[maxn], cnt;
char in[maxn][maxn];

int main()
{
	int T;
	scanf("%d", &T);

	for(int kase = 1; kase <= T; kase++) {
		cnt = 0;
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(hor, 0, sizeof(hor));
		memset(ver, 0, sizeof(ver));

		scanf("%d%d%d%d", &R, &C, &H, &V);

		for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) {
			scanf(" %c", &in[i][j]);
			if(in[i][j] == '@') {
				cnt++;
				row[i]++;
				col[j]++;
			}
		}

		printf("Case #%d: ", kase);

		int sum, W, cut;
		bool one = true, two = true;
		if(!(cnt%((H+1)*(V+1)))) {

			//case one: vertical cuts
			W = cnt/(V+1);
			sum = cut = 0;
			for(int i = 0; i < C && cut != V; i++) {
				sum += col[i];
				if(sum == W) {
					sum = 0;
					ver[++cut] = i+1;
				}
			}
			if(cut != V) one = false;
			else ver[V+1] = C;

			//case two: horizontal cuts
			W = cnt/(H+1);
			sum = cut = 0;
			for(int i = 0; i < R && cut != H; i++) {
				sum += row[i];
				if(sum == W) {
					sum = 0;
					hor[++cut] = i+1;
				}
			}
			if(cut != H) two = false;
			else hor[H+1] = R;

			if(one && two) {
				bool ok = true;

				W = cnt/((H+1)*(V+1));
				for(int i = 0; i <= H; i++)
					for(int j = 0; j <= V; j++) {
						sum = 0;
						for(int r = hor[i]; r < hor[i+1]; r++)
							for(int c = ver[j]; c < ver[j+1]; c++)
								sum += (in[r][c] == '@')? 1 : 0;
						if(sum != W) ok = false;
					}

				puts(ok? "POSSIBLE" : "IMPOSSIBLE");
			} else puts("IMPOSSIBLE");
		} else puts("IMPOSSIBLE");
	}

	return 0;
}
