#include<stdio.h>
#include<string.h>
#include<algorithm>
using std::swap;
const int maxl = 250 + 10;

char* multiply(char X[maxl], char Y[maxl])
{
	int X_len = strlen(X);
	int Y_len = strlen(Y);

	int P[2*maxl];
	int P_len = X_len + Y_len - 1;
	memset(P, 0, sizeof(P));

	if((X_len == 1 && X[0] == '0') || (Y_len == 1 && Y[0] == '0')) {
		P_len = 1;
		P[0] = 0;
	} else {
		for(int i = 0; i < X_len/2; i++) swap(X[X_len-i-1], X[i]);
		for(int i = 0; i < Y_len/2; i++) swap(Y[Y_len-i-1], Y[i]);
		for(int i = 0; i < X_len; i++)
			for(int j = 0; j < Y_len; j++) {
				int a = X[i]-'0', b = Y[j]-'0';
				P[i+j] += a * b;
			}

		for(int i = 0; i < P_len; i++) {
			P[i+1] += P[i] / 10;
			P[i] %= 10;
		}
		if(P[P_len]) P_len++;
	}

	static char Z[maxl];
	int Z_len = P_len;
	for(int i = 0; i < Z_len; i++) Z[i] = P[i] + '0';

	for(int i = 0; i < (Z_len)/2; i++) swap(Z[Z_len-i-1], Z[i]);
	Z[Z_len] = '\0';

	return Z;
}

int main()
{
	char X[maxl], Y[maxl];
	while(1) {
		memset(X, 0, sizeof(X));
		memset(Y, 0, sizeof(Y));
		if(scanf("%s%s", X, Y) == EOF) break;
		printf("%s\n", multiply(X, Y));
	}

	return 0;
}
