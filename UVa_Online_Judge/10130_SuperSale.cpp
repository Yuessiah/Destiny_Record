#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;

int N, P[maxn], W[maxn], G, MW, pack[maxn], S[maxn];

int main()
{
	S[0] = 0;

	int T;
	scanf("%d", &T);

	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d%d", &P[i], &W[i]);
			S[i] = S[i-1] + W[i];
		}

		int sum = 0;
		scanf("%d", &G);
		while(G--) {
			memset(pack, 0, sizeof(pack));

			scanf("%d", &MW);
			for(int i = 1; i <= N; i++) {
				int bound = max(W[i], MW-(S[N]-S[i-1])); //constant optimization
				for(int j = MW; j >= bound; j--) pack[j] = max(pack[j], pack[j-W[i]]+P[i]);
			}

			sum += pack[MW];
		}
		printf("%d\n", sum);
	}

	return 0;
}
