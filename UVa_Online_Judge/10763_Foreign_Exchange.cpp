#include<cstdio>
#include<map>
#include<utility>
#define PAIR pair<int, int>
using namespace std;

const int maxn = 500000 + 10;

int n;
map<PAIR, int> stus;

int main()
{
	while(scanf("%d", &n) && n) {
		stus.clear();

		for(int i = 0; i < n; i++) {
			int from, to;
			scanf("%d %d", &from, &to);

			if(stus.count(PAIR(from, to))) stus[PAIR(from, to)]++;
			else { stus[PAIR(from, to)] = 1; }

			if(stus.count(PAIR(to, from))) {
				stus[PAIR(to, from)]--;
				if(!stus[PAIR(to, from)]) stus.erase(PAIR(to, from));
				stus[PAIR(from, to)]--;
				if(!stus[PAIR(from, to)]) stus.erase(PAIR(from, to));
			}
		}

		if(stus.size()) puts("NO");
		else puts("YES");
	}

	return 0;
}
