#include<cstdio>
#include<stack>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	getchar();

	while(n--) {
		stack<char> S;
		char c;
		bool ok = true;

		while((c = getchar()) && c != '\n') {
			if(c == ']' || c == ')') {
				if(S.empty()) { ok = false; continue; }
				if(S.top() == '[' && c == ']') { S.pop(); continue; }
				if(S.top() == '(' && c == ')') { S.pop(); continue; }
				ok = false;
			} else S.push(c);
		}

		if(!S.empty() || !ok) puts("No");
		else puts("Yes");
	}

	return 0;
}
