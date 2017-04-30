#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 100;

struct cake {
	long long R, H;
	cake(long long r=0, long long h=0): R(r), H(h){}
}P[maxn], P2[maxn];

int N, K;
long long maxsur;

bool cmp(const cake& A, const cake& B) {
	if(A.R == B.R) return A.H < B.H;
	return A.R < B.R;
}

bool cmp2(const cake& A, const cake& B) {
	long long sideA = 2*A.R*A.H;
	long long sideB = 2*B.R*B.H;
	return sideA > sideB;
}

int main()
{
	int T, kase=0;
	scanf("%d", &T);

	while(T--) {
		scanf("%d%d", &N, &K);
		for(int i = 0; i < N; i++) scanf("%lld%lld", &P[i].R, &P[i].H);

		maxsur = 0;
		sort(P, P+N, cmp);
		for(int i = K-1; i < N; i++) {
			long long sur = P[i].R*P[i].R + 2*P[i].R*P[i].H;

			for(int j = 0; j < i; j++) P2[j] = cake(P[j].R, P[j].H);
			sort(P2, P2+i, cmp2);
			for(int j = 0; j < K-1; j++) sur += 2*P2[j].R*P2[j].H;

			maxsur = max(maxsur, sur);
		}

		printf("Case #%d: %.9lf\n", ++kase, maxsur*acos(-1));
	}

	return 0;
}
