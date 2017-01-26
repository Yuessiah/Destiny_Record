#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxr = 10000 + 10;

int n;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		vector<int> cor[maxr*2], Y;

		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			cor[y+maxr].push_back(x*2);
			Y.push_back(y+maxr);
		}

		int y = Y[0];
		sort(cor[y].begin(), cor[y].end());
		int verlx = cor[y][cor[y].size()-1] - (cor[y][cor[y].size()-1] - cor[y][0])/2;

		bool ok = true;
		for(int i = 0; i < Y.size(); i++) {
			y = Y[i];
			sort(cor[y].begin(), cor[y].end());

			int sz = cor[y].size();
			for(int j = 0; j < (sz%2? sz/2+1 : sz/2); j++) if(\
					verlx-cor[y][j] != cor[y][sz-j-1]-verlx) {
				ok = false; break;
			}
			if(!ok) break;
		}

		if(ok) puts("YES");
		else puts("NO");
	}

	return 0;
}
