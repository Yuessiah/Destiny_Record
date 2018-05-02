#include<bits/stdc++.h>
using namespace std;

const int maxm = 110;
const long upbound = log2(100)*1e9 + 1;

struct ingredient { int R1, R2; };
int M;
long gram[maxm], stock[maxm];
vector<ingredient> F; //Formula

bool alchemy(int metal, long req) {
	if(stock[metal] < 0) return false;

	stock[metal] -= req;
	if(stock[metal] >= 0) return true;

	if(alchemy(F[metal].R1, -stock[metal]) && alchemy(F[metal].R2, -stock[metal])) {
		stock[metal] = 0;
		return true;
	}

	return false;
}

long bs(long l, long r) {
	while(r > l) {
		long m = l + (r-l)/2;
		memcpy(stock, gram, sizeof(stock));
		if(alchemy(1, m)) l = m + 1;
		else r = m;
	}

	return l-1;
}

int main()
{
	int T, kase = 0;
	scanf("%d", &T);

	while(T--) {
		F.clear();

		scanf("%d", &M);

		int R1, R2;
		F.push_back((ingredient){0, 0}); //dummy
		for(int i = 0; i < M; i++) {
			scanf("%d%d", &R1, &R2);
			F.push_back((ingredient){R1, R2});
		}
		for(int i = 1; i <= M; i++) scanf("%ld", &gram[i]);

		printf("Case #%d: %ld\n", ++kase, bs(0, upbound));
	}

	return 0;
}
