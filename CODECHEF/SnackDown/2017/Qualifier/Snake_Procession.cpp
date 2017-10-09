#include<cstdio>

int main()
{
	int R, L;
	scanf("%d", &R);
	while(R--) {
		bool ok = true;

		scanf("%d", &L);
		char tmp = 'T', C;
		for(int i = 0; i < L; i++) {
			scanf(" %c", &C);
			if(C == '.') continue;
			if(C != tmp) tmp = C;
			else ok = false;
		} if(tmp != 'T') ok = false;

		if(ok) puts("Valid");
		else puts("Invalid");
	}

	return 0;
}
