#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
const int maxi = 6 + 5, maxc = 8 + 5, maxo = 9 + 5;

int I, need[maxi], dp[maxo][maxo][maxo][maxo][maxo][maxo];
int n_c, n_o;

struct combos {
	int list[maxi];
	int price;
}combo[maxc+maxi];

int solve()
{
	for(int i = 0; i < n_c; i++) {
		dp[combo[i].list[0]][combo[i].list[1]][combo[i].list[2]][combo[i].list[3]][combo[i].list[4]][combo[i].list[5]] = combo[i].price;

		for(int a = combo[i].list[0]; a < maxo; a++)
			for(int b = combo[i].list[1]; b < maxo; b++)
				for(int c = combo[i].list[2]; c < maxo; c++)
					for(int d = combo[i].list[3]; d < maxo; d++)
						for(int e = combo[i].list[4]; e < maxo; e++)
							for(int f = combo[i].list[5]; f < maxo; f++) {
								int& prev = dp[a-combo[i].list[0]][b-combo[i].list[1]][c-combo[i].list[2]][d-combo[i].list[3]][e-combo[i].list[4]][f-combo[i].list[5]];
								if(prev && dp[a][b][c][d][e][f]) dp[a][b][c][d][e][f] = min(dp[a][b][c][d][e][f], prev+combo[i].price);
								else if(prev) dp[a][b][c][d][e][f] = prev + combo[i].price;
							}
	}
	return dp[need[0]][need[1]][need[2]][need[3]][need[4]][need[5]];
}

int main()
{

	while(~scanf("%d", &I)) {
		n_c = n_o = 0;
		memset(combo, 0, sizeof(combo));
		memset(dp, 0, sizeof(dp));
		memset(need, 0, sizeof(need));

		for(int i = 0; i < I; i++) {
			combo[n_c].list[i] = 1;
			scanf("%d", &combo[n_c++].price);
		}

		int tmp;
		scanf("%d", &tmp);
		while(tmp--) {
			for(int j = 0; j < I; j++) scanf("%d", &combo[n_c].list[j]);
			scanf("%d", &combo[n_c++].price);
		}

		/*
			 for(int i = 0; i < n_c; i++) {
			 for(int j = 0; j < I; j++) printf("%d ", combo[i].list[j]);
			 printf("%d\n", combo[i].price);
			 }
			 */

		scanf("%d", &n_o);
		for(int i = 0; i < n_o; i++) {
			for(int j = 0; j < I; j++) scanf("%d", &need[j]);
			printf("%d\n", solve());
		}
	}

	return 0;
}
