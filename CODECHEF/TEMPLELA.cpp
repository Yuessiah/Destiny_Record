#include<cstdio>
#include<cstdlib>

int main()
{
	int S, N, H;
	scanf("%d", &S);
	while(S--) {
		bool ok = true;

		scanf("%d", &N);
		for(int i = 0, past = 0; i < N; i++) {
			scanf("%d", &H);
			if(i == 0 && H != 1) ok = false;
			if(i == N-1 && H != 1) ok = false;
			if(abs(past-H) != 1) ok = false;
			past = H;
		}

		if(ok) puts("yes");
		else puts("no");
	}

	return 0;
}
