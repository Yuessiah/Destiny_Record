#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int maxn = 10+5;

int main()
{
	char a[maxn], b[maxn];
	while(scanf("%s%s", a, b)) {
		if(a[0] == '0' && b[0] == '0') break;

		int a_len = strlen(a);
		int b_len = strlen(b);
		reverse(a, a+a_len);
		reverse(b, b+b_len);

		int count = 0;
		int len = max(a_len, b_len), c = 0, s;
		for(int i = 0; i < len; i++) {
			int p = a[i]-'0', q = b[i]-'0';
			if(isdigit(a[i]) && isdigit(b[i])) {
				c = (p+q+c)/10;
				if(c > 0) count++;
			} else if(isdigit(a[i])) {
				c = (p+c)/10;
				if(c > 0) count++;
			} else if(isdigit(b[i])) {
				c = (q+c)/10;
				if(c > 0) count++;
			}
		}

		if(count == 0) printf("No carry operation.");
		if(count == 1) printf("1 carry operation.");
		if(count > 1) printf("%d carry operations.", count);
		putchar('\n');

//		memset(a, 0, sizeof(a));
//		memset(b, 0, sizeof(b));
	}

	return 0;
}
