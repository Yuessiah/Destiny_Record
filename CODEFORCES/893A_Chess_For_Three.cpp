#include<bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	int p, v[3] = {1, 1, 0};
	bool ok = true;
	for(int i = 0; i < n; i++) {
		scanf("%d", &p);
		switch(p) {
			case 1:
				if(v[0] != 1) ok = false;
				if(v[1]) { v[1] = 0; v[2] = 1; }
				else if(v[2]) { v[1] = 1; v[2] = 0; }
				break;
			case 2:
				if(v[1] != 1) ok = false;
				if(v[0]) { v[0] = 0; v[2] = 1; }
				else if(v[2]) { v[0] = 1; v[2] = 0; }
				break;
			case 3:
				if(v[2] != 1) ok = false;
				if(v[0]) { v[0] = 0; v[1] = 1; }
				else if(v[1]) { v[0] = 1; v[1] = 0; }
				break;
		}
	}

	if(ok) puts("YES");
	else puts("NO");
}

int main()
{
	while(~scanf("%d", &n)) {
		solve();
	}

	return 0;
}
