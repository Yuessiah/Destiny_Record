#include<cstdio>

int main()
{
	int x, y, z, a, b, c, q, w, e, x_1, y_1, z_1;

	while(~scanf("%d%d%d", &a, &b, &c)) {
		x_1 = y_1 = z_1 = 1;
		for(int i = 1; i < 7; i++) {
			scanf("%d%d%d", &x, &y, &z);
			if(a == x) x_1++; else q = x;
			if(b == y) y_1++; else w = y;
			if(c == z) z_1++; else e = z;
		}

		printf("%d %d %d\n",
				(x_1==4)? q : a,
				(y_1==4)? w : b,
				(z_1==4)? e : c);
	}

	return 0;
}
